#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>

#define MAX 256

char *cmd[MAX];
int cmd_total;

void get_cmd(char *command){
	char *p;
	char sub[]=" ";
	p=strtok(command,sub);
	if(p!=NULL){
		cmd[0]=p;
		++cmd_total;
	}
	while((p=strtok(NULL,sub))){
		cmd[cmd_total]=p;
		++cmd_total;
	}
	cmd[cmd_total]=NULL;
}

void print_cmd(){
	int i;
	for(i=0;i<cmd_total;++i)	printf("%s\n",cmd[i]);
}

void set_cmd(){
	int i;
	for(i=0;i<cmd_total;++i)	cmd[i]=NULL;
	cmd_total=0;
}

int has_redir(){
	int i;
	for(i=0;i<cmd_total;++i){
		if(strcmp(cmd[i],">")==0)	return i;
	}
	return -1;
}

void exec_cmd(){
	pid_t pid;
	int fd,loc;
	int fd_origin;
	loc=has_redir();
	if(loc!=-1){
		fd=open(cmd[loc+1],O_CREAT|O_RDWR,0666);
		fd_origin=dup(1);
		dup2(fd,1);
	}
	pid=fork();
	if(pid==0){
		if(loc!=-1)	cmd[loc]=NULL;
		execvp(cmd[0],cmd);
	}
	if(loc!=-1)	dup2(fd_origin,1);
	waitpid(pid,NULL,0);
}

int main(){
	char com[MAX];
	pid_t pid;
	while(1){
		printf("$ ");
		gets(com);
		get_cmd(com);
		if(strcmp(cmd[0],"cd")==0){
			if(chdir(cmd[1])!=0)	puts("cd error\n");
		}else{
			if(strcmp(cmd[0],"exit")==0)	exit(0);
			else	exec_cmd();
		}
		set_cmd();
	}
	return 0;
}
