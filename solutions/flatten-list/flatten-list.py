def removeNestings(l,res):
    for i in l:
        if isinstance(i, list):
            removeNestings(i,res)
        else:
            res.append(i)
    return res

def flattenList(lst):
    return removeNestings(lst, [])

if __name__ == '__main__':
    instance = [1,[[[2,[[3]],4],5,7],[8,[9,[[[[[10]]]]],[11,12,[13,14],15],16]]],[17],[[[18,19],20],21,22],23,[[[[[24,25]]]]]]    
    output = flattenList(instance)
    print(f"{instance = }")
    print(f"{output = }")
    for i in output:
        assert isinstance(i, list) is False