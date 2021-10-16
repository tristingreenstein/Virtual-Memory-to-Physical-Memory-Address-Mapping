# Virtual-Memory-to-Physical-Memory-Address-Mapping
To map a process (within virtual memory) to physical memory, translating a virtual address to a physical address, involving a custom-sized page table.
# Objective: 
• To map a process (within virtual memory) to physical memory, translating a virtual 
address to a physical address, involving a custom-sized page table. 
# Inputs: 
• The total size of physical memory (in words) 
• The page size (words/page) 
• The replacement policy (LRU=0, FIFO=1) 
# Outputs: 
• The corresponding physical address for a virtual address 
• A message indicating a page fault (if any) in the page table
• The current contents of the page table (virtual page, page frame, last accessed cycle)
# Specification: 
The program translates a virtual address within a process to a physical address based on 
selecting from a menu of choices. Each choice calls the appropriate procedure, where the 
choices are: 
1) Set parameters for physical memory and page table
2) Map virtual address to physical address
3) Print page table
4) Quit program 
Upon entering the parameters, the page table is to be dynamically allocated based on the 
total number of page frames. The pages of the process will be mapped to the page frames 
on demand in the page frame order 0,1,2,3,…
