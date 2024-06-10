def count_substring(string, sub_string):
    count=0
    i=0
    while i <= len(string):
        i = string.find(sub_string, i)
        if i == -1:
            break
        i+=1
        count+=1
        
    return count