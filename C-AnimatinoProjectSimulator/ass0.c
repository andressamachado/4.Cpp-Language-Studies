/******************************************************************************************************************
Filename:ass0.c
Version: 1.0
Author: Andressa Pessoa de Araujo Machado [040923007] & Professors
Assignment Number:0
Assignment Name:Animation Project in C
Course Name: C++ Programming
Course Code:CST8219
Lab Section Number: 302
Professor`s Name: Surbhi Bahri & Abdullah Kadri
Due Date: 2019/01/28
Submission Date:2019/01/24
List of source files: ass0.c
Purpose: Simulates an Animation Application using Linked List. Until the User quits the program. It will read a 
valid response from the keyboard in order to go through the process of either creating a frame of animation,editing 
a frame ,displaying all frames or even delete a frame.
******************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build

#include <crtdbg.h>
#include <stdio.h>
#include <string.h>

typedef enum { FALSE = 0, TRUE } BOOL;

struct Frame {
	char* frameName;
	struct Frame* pNext;
};

typedef struct {
	char* animationName;
	struct Frame* frames;
}Animation;

// Forward declarations
void InitAnimation(Animation*);
void InsertFrame(Animation*);
void DeleteFrame(Animation*);
void EditFrame(Animation*);
void ReportAnimation(Animation*);
void CleanUp(Animation*);


/***********************************************
Function name: main
Purpose: main function

In parameters: None
Out Parameters: 0 for Success

Version: 1.0
Author: Surbhi Bahri
************************************************/
int main(void){
	char response;
	BOOL RUNNING = TRUE;
	Animation RG;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	InitAnimation(&RG);

	while (RUNNING){

		printf("MENU\n 1. Insert a Frame at the front\n 2. Delete last Frame\n 3. Edit a Frame\n 4. Report the Animation\n 5. Quit\n"); 
		scanf("%c", &response);

		switch (response){
		case '1':InsertFrame(&RG); break;
		case '2':DeleteFrame(&RG); break;
		case '3':EditFrame(&RG); break;
		case '4':ReportAnimation(&RG); break;
		case '5':RUNNING = FALSE; CleanUp(&RG); break;

		default:printf("Please enter a valid option\n");
		}
	}
	return 0;
}

/***********************************************
Function name: InitAnimation
Purpose: Initializes the Linked List

In parameters: Animation* animation
Out Parameters: 0 for Success

Version: 1.0
Author: Andressa Machado
************************************************/
void InitAnimation(Animation* animation) {
	//Holds the user input for the animation title
	char user_input[256];
	//Holds the number of characters in the animation title
	int title_length;

	do {
		printf("Please enter the Animation name: ");
		fgets(user_input, sizeof(user_input), stdin);

		title_length = (unsigned)strlen(user_input);
	} while(user_input[0] == '\n');

	//allocates the exact memory needed to hold the animation`s name
	(*animation).animationName = (char*)malloc((title_length) * sizeof(char) + 1);

	//checks if the allocation was successful and returned a pointer
	if ((*animation).animationName == NULL) {
		printf("Failure to allocate memory");
	}
	else {
		strcpy((*animation).animationName, user_input);
		(*animation).frames = NULL;
	}
}

/***********************************************
Function name: InsertFrame
Purpose: Inserts a new Frame (node) to start of the Animation Frame list (Linked List)

In parameters: Animation* animation
Out Parameters: 0 for Success

Version: 1.0
Author: Andressa Machado

************************************************/
void InsertFrame(Animation* animation) {
	//Holds the user input for the frame title
	char user_input[256];
	//Holds the number of characters in the frame title
	int title_length;
	//holds return of getc
	int getc_return;

	// cleaning the buffer of \n after scanf of line 70 [Reads the menu option from the user in the main]
	getc_return = getc(stdin);

	//Making sure the user doesn`t only hits enter
	do {
		printf("Insert a Frame in the Animation");
		printf("\nPlease enter the frame name: ");
		fgets(user_input, sizeof(user_input), stdin);
	} while (user_input[0] == '\n');

	title_length = (unsigned)strlen(user_input);

	//Creating the Frame to be added by allocating memory for it
	struct Frame* new_frame = malloc(sizeof(struct Frame));

	//checks if the memory allocation to hold the new Frame was successful and returned a pointer
	if (new_frame == NULL) {
		free(new_frame);
		printf("Failure to allocate memory");
	} else {
		//allocates the exact memory needed to hold the frame`s name
		new_frame->frameName = (char*)malloc((title_length) * sizeof(char) +1);
		
		//checks if the memory allocation to hold the frame`s name was successful and returned a pointer
		if (new_frame->frameName == NULL) {
			free(new_frame->frameName);
			printf("Failure to allocate memory");
		}
		else {
			//Coping the user input to the frameName field
			//strtok() divides the string at the /n char, returning the desired
			strcpy(new_frame->frameName, strtok(user_input, "\n"));
			
			//Adding the new frame to the Animation list.
			new_frame->pNext = animation->frames;
			animation->frames = new_frame;
		}
	}
}

/***********************************************
Function name: DeleteFrame
Purpose: Delete the last Frame(node) in the Animation(Linked List)

In parameters: Animation* animation
Out Parameters: 0 for Success

Version: 1.0
Author: Andressa Machado

************************************************/
void DeleteFrame(Animation* animation) {
	//holds return of getc that cleans the buffer
	int getc_return;
	getc_return = getc(stdin);

	//Checking if the Animation(LL) has any frame(Node)
	if (animation->frames == NULL) {
		printf("Your animation has no frame. Returning...");
		return;
	}

	//Creating a temporary Structure Frame and coping the very first Frame(Node) added to the Animation(LL)
	struct Frame* current_frame = animation->frames;

	//In case the Animation(LL) has only one Frame(Node)
	if (current_frame->pNext == NULL) {
		animation->frames = NULL;
		free(current_frame);
		return;
	}

	//Iterating through the Animation(LL) to find the last Frame to be deleted, setting it to the variable
	//that is holding the last Frame(Node). 
	while (current_frame->pNext->pNext != NULL) {
		current_frame = current_frame->pNext;
	}

	//deletting the last frame and freeing its memory
	free(current_frame->pNext);
	current_frame->pNext = NULL;
}

/***********************************************
Function name: EditFrame
Purpose: Changes one of the attributes of the struct(frameName).

In parameters: Animation* animation
Out Parameters: 0 for Success

Version: 1.0
Author: Andressa Machado

************************************************/
void EditFrame(Animation* animation) {
	//Holds the size of the Animation Linked List
	int llsize = 0;
	//Holds the desired index chosen by the user
	int user_input_index = 0;
	//Holds the user input for the frame`s new title
	char user_input[256];
	//Holds the number of characters in the frame title
	int title_length;

	//holds return of getc that cleans the buffer
	int getc_return;
	getc_return = getc(stdin);

	printf("Edit a Frame in the Animation");

	//In case the Animation(LL) has only the head and zero Frames(Nodes), leaves the function
	if (animation->frames == NULL) {
		printf("/nThere is no frame to be edit.");
		return;
	}

	//Creating a temporary Structure Frame and coping the very first Frame(Node) added to the Animation(LL)
	struct Frame* current_frame = animation->frames;

	//While it is not the last node, increase the size and move one node forward.
	while (current_frame != NULL) {
		llsize++;
		current_frame = current_frame->pNext;
	}

	//Holds the int value returned by the function scanf
	int scanf_return; 

	//Making sure the user doesn`t enter a char
	do {
		printf("\nThere are %d Frame(s) in the list. Please specify the index (<=%d) to edit at: ", llsize, llsize - 1);
		scanf_return = scanf("%d", &user_input_index);
		getc_return = getc(stdin);
	} while (scanf_return == 0 || (user_input_index >= llsize || user_input_index < 0) || user_input_index == '\n');


	//reset values to be used again in the loop. Allowing find the correct node.
	current_frame = animation->frames;
	llsize = 0;

	//while not the last node, look for the one chosen by the user.
	while (current_frame != NULL) {

		//In case the Frame is found, manage the updating 
		if (llsize == user_input_index) {

			do {
				printf("The name of this Frame is %s. What do you wish to replace it with?", current_frame->frameName);
				fgets(user_input, sizeof(user_input), stdin);
			} while (user_input[0] == '\n');

			title_length = (unsigned)strlen(user_input);

			free(current_frame->frameName);

			//allocates the exact memory needed to hold the frame`s name
			current_frame->frameName = (char*)malloc((title_length)*sizeof(char) + 1);

			//Coping the user input to the frameName field
			strcpy(current_frame->frameName, strtok(user_input, "\n"));

			return;
		}

		//increase the value if not the correct node
		llsize++;
		//move one node forward
		current_frame = current_frame->pNext;
	}
}

/***********************************************
Function name: ReportAnimation
Purpose: Prints the Animation Linked List.

In parameters: Animation* animation
Out Parameters: 0 for Success

Version: 1.0
Author: Andressa Machado

************************************************/
void ReportAnimation(Animation* animation) {
	//holds return of getc
	int getc_return;
	//cleaning buffer
	getc_return = getc(stdin);

	printf("Animation name is %s", animation->animationName);
	printf("Report the Animation");

	struct Frame* current_frame = animation->frames;
	int i = 0;

	//While not the last Frame(Node), continue printing the frame`s names
	while (current_frame != NULL) {

		printf("\nImage #%d, file name = %s", i, current_frame->frameName);
		current_frame = current_frame->pNext;
		i++;
	}
	printf("\n");
}

/***********************************************
Function name: CleanUp
Purpose: Clean up the memory allocated for the Animation Linked List.

In parameters: Animation* animation
Out Parameters: 0 for Success

Version: 1.0
Author: Andressa Machado

************************************************/
void CleanUp(Animation* animation) {
	//Holds the very first Frame Node of the Animation Linked List
	struct Frame* current_frame = animation->frames;
	//Temporary variable used to get the next Frame(Node) of the Animation LL
	struct Frame* temp_next;

	//While Frames(Node) in the Animation LL, pass through  the LL
	while (current_frame != NULL) {
		//Get the next node, so the current can be deleted. 
		temp_next = current_frame->pNext;

		free(current_frame->frameName);
		free(current_frame);

		current_frame = temp_next;
	}

	//Deleting the Animation LL from the heap
	free(animation->animationName);
	//Making sure we dont have a dangling pointer. 
	animation = NULL;
}


