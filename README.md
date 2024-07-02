This repository includes small pieces of code I've worked on while pursuing my degree.

---Explanations---

* MalwareDev-ProcessInjection - MALICIOUS SHELLCODE from msfvenom REMOVED, need to add calc.exe shellcode. This code was written following concepts in the Youtube video, "Malware Development: Process Injection" by Crow, following Windows API documentation. Many additions were made for my own learning. Written in MS Visual Studio 2022. The program uses Windows API to create a handle to a process specified by the User, allocate memory to the process, write malicious shellcode into memory, and execute a remote thread using the allocation address. The result is malicious shellcode injection, although this implementation is extremely noisy.

* MalwareDev-Processes-Handles-Threads - This code was written following concepts in the Youtube video, "Malware Development: Processes, Threads, and Handles" by Crow, following Windows API documentation. Many additions were made for my own learning. Written in VSCode. The program uses Windows API to create an instance of Wireshark (Or any program), prompts the User with a MessageBox, and ensures a clean termination of the process (depending on security attributes of said process.) 

* CryptoPython.py - This project is based on the Udemy Course 'Cryptography and Hashing Fundamentals in Python and Java' by, 'Holczer Balazs'. The program is a mix of my own implementations and learning with the mathematical/programming concepts taught in Balazs' course. The script gathers User inputs in a terminal and can perform basic brute forcing and frequency analysis against a Caesar Cipher. Future plans are to follow the rest of Balazs' Course to include implementations of AES, RSA, and ECC.

* Into to Python Final : Punnet Square Generator - The script uses a class to gather User inputs in a terminal including the Trait Name, Letter, Zygosity, and Recessive/Dominant attributes. The script uses this information to output a completed 4x4 punnet square with accompanied percentages for each phenotype.



