### Ransom Note
- Harold is a kidnapper who wrote a ransom note, but now he is worried it will be traced back to him through his handwriting. He found a magazine and wants to know if he can cut out whole words from it and use them to create an untraceable replica of his ransom note. The words in his note are case-sensitive and he must use only whole words available in the magazine. He cannot use substrings or concatenation to create the words he needs.
- Given the words in the magazine and the words in the ransom note, print Yes if he can replicate his ransom note exactly using whole words from the magazine; otherwise, print No.
- For example, the note is "Attack at dawn". The magazine contains only "attack at dawn". The magazine has all the right words, but there's a case mismatch. The answer is No.
- It must print Yes if the note can be formed using the magazine, or No.

- Instance format:
    - The first line contains two space-separated integers m and n, the numbers of words in the magazine and the note.
    - The second line contains m space-separated strings, each magazine[i]
    - The third line contains n space-separated strings, each note[i]

- **Input**:
````bash
        6 4
        give me one grand today night
        give one grand today
````

- **Output**:
````bash
        Yes
````

- [Solution](main.py)

#### Running
- Running a instance:
````bash
    python main.py "path_instance"
````

- Example: running a instance "input1":
````bash
    python main.py instances/input1
````