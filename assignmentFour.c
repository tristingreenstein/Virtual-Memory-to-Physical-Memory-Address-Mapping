#include <stdio.h>
#include <stdlib.h>

/* Define page table as dynamic structure containing:
virtual page, page frame, last access cycle
and initialize variable as pointer to structure */
struct node
{
    int vp;
    int pf;
    int accessed;
} *pt = NULL;
typedef struct node pt_type;
/* Declare global var's */
int pm_size;
int page_size;
int replace;
int num_rows;
int last_row = -1;
/**************************************************************/
void optionOne()
{
/* Declare local var's */
int i = 0;
/* Prompt for total page frame area size, individual page size, and replacement policy */
printf("\n\nEnter main memory size (words): ");
scanf("%d",&pm_size);
printf("\nEnter page size (words/page): ");
scanf("%d",&page_size);
printf("\nEnter replacement policy (0=LRU, 1=FIFO): ");
scanf("%d",&replace);
num_rows = (pm_size/ page_size);
/* Allocate and initialize page table based on number of entries */
pt = (pt_type *)(malloc(num_rows*sizeof(pt_type)));

for(i= 0; i<num_rows;i++)
{
    pt[i].vp = -1;
    pt[i].accessed=-1;
}

return;
}


/***************************************************************/
void optionTwo()
{
    /* Declare local var's */
    int vm_addr;
    int vp;
    int offset;
    int i = 0;
    int j = 0;
    int k = 0;
    int temp_pf;
    int pm_addr;

    /* Prompt for virtual address */
    printf("\n Enter virtual memory address to access: ");
    scanf("%d",&vm_addr);
    /* Translate virtual address to virtual page and offset*/
    vp = vm_addr / page_size;
    offset = (vm_addr % page_size);
    /* Check for end of table, unallocated entry, or matched entry in table
     while none of three cases, keep looping */
    while((i < num_rows)&&(pt[i].vp != -1) && (pt[i].vp != vp))
    {
        pt[i].accessed++;
        i++;
    }
    /* In case of end of table,
    replace either LRU or FIFO entry (top entry in page table),
    print message */
    if(i == num_rows)
    {
        temp_pf = pt[0].pf;
        for(j = 0;j<=num_rows-2;j++)
        {
            pt[j] = pt[j+1];
        }
        pt[num_rows-1].vp = vp;
        pt[num_rows-1].pf = temp_pf;
        pt[num_rows-1].accessed=0;
        printf("\nPage Fault!");
    }
    /* In case of unallocated entry,
    set entry according to virtual page and page frame,
    print message */
    else if(pt[i].vp == -1)
    {
        pt[i].vp = vp;
        pt[i].pf = i;
        pt[i].accessed = 0;
        last_row++;
    }
    /* In case of hit in page table,
    calculate physical address and print message,
    update page table if LRU policy */
    else
    {
        if(replace == 0)
        {
            temp_pf = pt[i].pf;
            for(k = i;k<last_row;k++)
            {
                pt[k] = pt[k+1];
                pt[k].accessed++;
            }
            pt[last_row].vp = vp;
            pt[last_row].pf = temp_pf;
            pt[last_row].accessed=0;
        }
        pm_addr = temp_pf*pm_size+offset;
        printf("\nVirtual Address maps %d the Physical Page %d",vm_addr,pm_addr);
    }
    return;
}


/***************************************************************/
void optionThree()
{
/* Declare local var's */
int i = 0;
/* For each valid entry in page table */
printf("\n");
for(i=0;i<= last_row;i++)
    printf("%d %d %d\n",pt[i].vp, pt[i].pf, pt[i].accessed);

	/* print virtual page number, page frame number, last accessed cycle */
return;
}


/**************************************************************/
int main()
{
/* Declare local var's */
    int userInput = -1;
/* Until user quits */
	/* print menu of options, prompt for user input, and select appropriate option */
	while(userInput != 4)
    {
        printf("\nVirtual memory to Main memory mapping");
        printf("\n-------------------------------------");
        printf("\n1) Set parameters\n2) Map virtual address\n3) Print page table\n4) Quit");
        printf("\n\nEnter selection: ");
        scanf("%d", &userInput);
        if(userInput == 1)
        {
            optionOne();
        }
        if(userInput ==2)
        {
            optionTwo();
        }
        if(userInput ==3)
        {
            optionThree();
        }

    }

return 1;
}

ngngngmgmgm