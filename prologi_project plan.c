#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This is the code as of now, updates for modules will happen
// Define the task structure
struct Task {
    char name[100];
    int difficulty;
    int importance;
    int due_date;
    float priority;
};

int main() {
    int num_tasks,choice;
    char pick;
    int day[7]={7,6,5,4,3,2,1};
    do{
	printf("SOS: Student Organizer Softwate\n");
	printf("\n1. Priorizitation List");
	printf("\n2. Due-date weekly calendar");
	printf("\n3. Exit");
	printf("\n\nInput the feature you want to see: ");
	scanf("%d",&choice);
	system("cls");

    struct Task tasks[num_tasks];

    // Get the details of each task from the user
	switch(choice){
		case 1: 
		printf("\nEnter the number of tasks: ");
    	scanf("%d", &num_tasks);
    	system("cls");
		    for(int i=0; i<num_tasks; i++) {
        printf("Enter the name of task %d: ", i+1);
        scanf("%s", tasks[i].name);
        printf("\nDifficulty scale");
        printf("\n1\tVery difficult\n2\tdifficult\n3\taverage\n4\teasy");
        printf("\nEnter the difficulty level of task %d (1-4): ", i+1);
        scanf("%d", &tasks[i].difficulty);
        
        printf("\nRank table");
        printf("\n1\tUrgent & Important\n2\tNot urgent & Important\n3\tUrgent & not important\n4\tNot urgent and not important");
        printf("\nEnter the Rank of task %d (1-4): ", i+1);
        scanf("%d", &tasks[i].importance);
        
        printf("\nWeek table");
        printf("\n1\tMonday\n2\tTuesday\n3\tWednesday\n4\tThursday\n5\tFriday\n6\tSaturday\n7\tSunday");
        printf("\nEnter the due date of task %d (1-7): ", i+1);
        scanf("%d", &tasks[i].due_date);
		system("cls");
        // Calculate the priority of each task
        tasks[i].priority = (float)(tasks[i].difficulty * tasks[i].importance) / day[tasks[i].due_date-1];
    }
		 // Sort the tasks based on their priority
   		 for(int i=0; i<num_tasks; i++) {
        	for(int j=i+1; j<num_tasks; j++) {
           		 if(tasks[i].priority > tasks[j].priority) {
                // Swap the tasks
                struct Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    // Print the tasks in ascending order of priority
    printf("\nPriorizitation list:\n");
    for(int i=0; i<num_tasks; i++) {
        printf("%s\t\n", tasks[i].name);
    }
    printf("\n\ngo back to menu?(y/n): ");
    scanf("%s",&pick);
		break;
	case 2: 
	printf("\nEnter the number of tasks: ");
    scanf("%d", &num_tasks);
    system("cls");
	for(int i=0; i<num_tasks; i++) {
        printf("Enter the name of task %d: ", i+1);
        scanf("%s", tasks[i].name);
        
        printf("\nWeek table");
        printf("\n1\tMonday\n2\tTuesday\n3\tWednesday\n4\tThursday\n5\tFriday\n6\tSaturday\n7\tSunday");
        printf("\nEnter the due date of task %d (1-7): ", i+1);
        scanf("%d", &tasks[i].due_date);
		system("cls");}
	// Define an array to store the tasks for each day of the week
    char week[7][100] = {"", "", "", "", "", "", ""};

    // Store the tasks under the appropriate day of the week in the week array
    for(int i=0; i<num_tasks; i++) {
        switch(tasks[i].due_date) {
            case 1:
                strcat(week[0], tasks[i].name);
                strcat(week[0], ", ");
                break;
            case 2:
                strcat(week[1], tasks[i].name);
                strcat(week[1], ", ");
                break;
            case 3:
                strcat(week[2], tasks[i].name);
                strcat(week[2], ", ");
                break;
            case 4:
                strcat(week[3], tasks[i].name);
                strcat(week[3], ", ");
                break;
            case 5:
                strcat(week[4], tasks[i].name);
                strcat(week[4], ", ");
                break;
            case 6:
                strcat(week[5], tasks[i].name);
                strcat(week[5], ", ");
                break;
            case 7:
                strcat(week[6], tasks[i].name);
                strcat(week[6], ", ");
                break;
            default:
                printf("Invalid due date entered for task %d!\n", i+1);
                break;
        }
    }
    printf("\nDue-Date Weekly Calendar\n");
    printf("\nMonday: %s\n", week[0]);
    printf("Tuesday: %s\n", week[1]);
    printf("Wednesday: %s\n", week[2]);
    printf("Thursday: %s\n", week[3]);
    printf("Friday: %s\n", week[4]);
    printf("Saturday: %s\n", week[5]);
    printf("Sunday: %s\n", week[6]);
    printf("\n\ngo back to menu?(y/n): ");
    scanf("%s",&pick);
    break;
    
    case 3:
    	printf("Goodbye! Thank you for using SOS!");
    	return 0;
    	break;	
    
    default: 
    	printf("invalid input");
    	printf("continue?(y/n): ");
    	scanf("%s",&pick);
    	break;
	}
	system("cls");
    }while (pick=='y'||pick=='Y');

    return 0;
}
