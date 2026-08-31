#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void sig(int s)
{
	printf("signal %d recu par le fils\n", s);
}

int main()
{
	FILE* fic = fopen("famille_pid.txt", "w");
	pid_t pid = fork();

	if(pid < 0)
	{
		perror("raté pas de fork\n");
		return -1;
	}else if(pid == 0)
	{
		signal(SIGUSR1, &sig);
		pause();
		printf("je suis ton fils. PID: %d, PPID: %d\n", getpid(), getppid());
		fprintf(fic, "je suis le fils et mon PID est %d\n", getpid());		// on print le fils en premier dans le fichier
		exit(0);
	}else
	{
		printf("je suis ton pere. PID: %d, PID du fils: %d\n", getpid(), pid);
	
		char p = 'a';
		printf("appuyer sur p pour envoyer un signal au fils\n");
		while(p != 'p')
		{
			scanf("%c", &p);
		}
		printf("envoie du signal 10 au fils\n");
		kill(pid, SIGUSR1);
		if(waitpid(pid, 0, 0) < 0)		// on attend la fin du fils
		{
			perror("raté fils pas attendu\n");
			return -1;
		}else
		{
			printf("le fils est mort\n");
		}

		fprintf(fic, "je suis le pere et mon PID est %d\n", getpid());		// on print le pere en deuxieme dans le fichier

		printf("meutre du fils, le pere se suicide\n");
	}
	fclose(fic);

	return 0;
}