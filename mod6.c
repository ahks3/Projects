//Mal Dev Module 6, practicing Windows memory management

//Headers
#include<stdio.h>
#include<windows.h>

//Function prototypes
static VOID printContents(LPVOID pAddress, INT exNumber);

INT main(VOID){

    //Initializing neccesary vars
    CHAR* cString = "MalDev ...";
    size_t cSize = strlen(cString) + 1;

    //Alloc using malloc
    LPVOID pAddress1 = malloc(cSize);
    if (pAddress1 == NULL){ //Check for valid addr
        printf("[!]Failed to allocate memory to pAddr1\n");
        free(pAddress1);
    }
    else{
        printContents(pAddress1, 1);
        memcpy(pAddress1, cString,cSize);
        printf("[-]AFTER malloc\n");
        printContents(pAddress1, 1);
        free(pAddress1);
    }

    printf("-----\n");
    //Alloc using HeapAlloc
    LPVOID pAddress2 = HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,cSize);
    if(pAddress2 == NULL){ //Check for valid addr
        printf("[!]Failed to allocate memory to pAddr2\n");
        HeapFree(GetProcessHeap(),0,pAddress2);
    }
    else{
        printContents(pAddress2, 2);
        memcpy(pAddress2,cString,cSize);
        printf("[-]AFTER HeapAlloc\n");
        printContents(pAddress2, 2);
        HeapFree(GetProcessHeap(),0,pAddress2);
    }

    printf("-----\n");
    //Alloc using LocalAlloc
    LPVOID pAddress3 = LocalAlloc(LPTR, cSize);
    if(pAddress3 == NULL){ //Check for valid addr
        printf("[!]Failed to allocate memory to pAddr3\n");
        LocalFree(pAddress3);
    }
    else{
        printContents(pAddress3, 3);
        memcpy(pAddress3,cString,cSize);
        printf("[-]AFTER LocalAlloc\n");
        printContents(pAddress3, 3);
        LocalFree(pAddress3);
    }



//Freeing memory
/*

    Allocating with malloc requires the use of the free function.

    Allocating with HeapAlloc requires the use of the HeapFree function.

    Allocating with LocalAlloc requires the use of the LocalFree function.
*/

    printf("-----\n");
    
    LPVOID pAddress4 = NULL;

    //Allocate using VirtualAlloc win32api
    if (!(pAddress4 = VirtualAllocEx( //Check to see if VirtualAlloc sucessfully allocates memory
            GetCurrentProcess(),
            NULL,
            cSize,
            MEM_RESERVE | MEM_COMMIT,
            PAGE_READWRITE
        )
    )) { //Print error and free memory
        printf("[!]Failed to allocate memory to pAddr4\nError code:%lu\n", GetLastError());
        
        VirtualFreeEx(
            GetCurrentProcess(),
            pAddress4,
            0,
            MEM_RELEASE
        );
    } //Proceed with printing operations
    else{
        printContents(pAddress4, 4);
        printf("[-]AFTER VirtualAllocEx\n");

        SIZE_T bytesWritten;
        WriteProcessMemory(
            GetCurrentProcess(),
            pAddress4,
            cString,
            cSize,
            &bytesWritten
        );
        printf("[-]%lu bytes written\n", bytesWritten);
        printContents(pAddress4, 4);

        VirtualFreeEx(
            GetCurrentProcess(),
            pAddress4,
            0,
            MEM_RELEASE
        );
    }
    
    printf("[+]Enter to Quit...\n");
    getchar();

    return EXIT_SUCCESS;
}

//Function definition
static VOID printContents(LPVOID pAddress, int exNumber){
    printf("[+]pAddress%d at 0x%p containing string %s\n", exNumber, pAddress, (CHAR*)pAddress);
}