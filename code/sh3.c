#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

#define MAX 255

char *cmd[MAX][MAX];
int cmd_total;

void get_sub_cmd(int loc,char *command){
	char *p;
	char sub[] = " ";
	int i = 0;
	p = strtok(command,sub);
	if(p!=NULL){
		cmd[loc][0] = p;
		++i;
	}
	while((p=strtok(NULL,sub))){
		cmd[loc][i] = p;
		++i;
	}
	cmd[loc][i] = NULL;
}
void get_cmd(char *command){
	char *p;
	char sub[] = "|";
	cmd_total = 0;
	p = strtok(command,sub);
	if(p!=NULL){
		cmd[0][0]=p;
		++cmd_total;
	}
	while((p=strtok(NULL,sub))){
		cmd[cmd_total][0]=p;
		++cmd_total;
	}
	int i;
	cmd[cmd_total][0]=NULL;
	for(i=0;i<cmd_total;++i){
		get_sub_cmd(i,cmd[i][0]);
	}
}
void print_cmd(){
	int i,j;
	for(i=0;i<cmd_total;++i){
		j=0;
		while(cmd[i][j]!=NULL){
			printf("%s\t",cmd[i][j]);
			++j;
		}
		printf("\n");
	}
}
void set_cmd(){
	int i;
	for(i=0;i<cmd_total;++i){
		cmd[i][0]=NULL;
	}
	cmd_total=0;
}
int has_redir_w(int loc){
	int i=0;
	while(cmd[loc][i]!=NULL){
		if(strcmp(cmd[loc][i],">")==0){
			return i;
		}
		++i;
	}
	return -1;
}
int has_redir_r(int loc){
	int i=0;
	while(cmd[loc][i]!=NULL){
		if(strcmp(cmd[loc][i],"<")==0){
			return i;
		}
		++i;
	}
	return -1;
}
void exec_cmd(int no_i){
	int fd,loc_w,loc_r;
	loc_r=has_redir_r(no_i);
	loc_w=has_redir_w(no_i);
	if(loc_w!=-1){
		cmd[no_i][loc_w]=NULL;
		fd=open(cmd[no_i][loc_w+1],O_CREAT|O_RDWR,0666);
		dup2(fd,1);
	}
	if(loc_r!=-1){
		cmd[no_i][loc_r]=NULL;
		fd=open(cmd[no_i][loc_r+1],O_CREAT|O_RDWR,0666);
		dup2(fd,0);
	execvp(cmd[no_i][0],cmd[no_i]);
}
void print_single_cmd(int index){
	int i=0;
	while(cmd[index][i]!=NULL){
		printf("%s\t",cmd[index][i]);
		++i;
	}
	printf("\n");
}
void exec_pipe(int no_i){
	int fd[2];
	pid_t pid;

	if(no_i==cmd_total-1){
		exec_cmd(no_i);
		return;
	}
	pipe(fd);
	pid=fork();
	if(pid==0){
		dup2(fd[0],0);
		close(fd[0]);
		close(fd[1]);
		exec_pipe(no_i+1);
	}else{
		if(no_i==0)	close(fd[0]);
		dup2(fd[1],1);
		close(fd[1]);
		close(fd[0]);
		exec_cmd(no_i);
	}
}
int main(){
	char com[MAX];
	pid_t pid;
	while(1){
		printf("$ ");
		gets(com);
		get_cmd(com);
		if(strcmp(cmd[0][0],"cd")==0){
			if(chdir(cmd[0][1])!=0){
				puts("cd error\n");
			}
		}else{
			if(strcmp(cmd[0][0],"exit")==0){
				exit(0);
			}else{
				pid = fork();
				if(pid==0)	exec_pipe(0);
				waitpid(pid,NULL,0);
			}
		}
		set_cmd();
	}
	return 0;
}
