""" map(<f>, <iterable>) """
lst = [1, 2, 3, 4, 5]
result = "{n} = {s}".format(n=" + ".join(map(str, lst)),
                            s=sum(lst))
print(result)  # 1 + 2 + 3 + 4 + 5 = 15


""" map(<f>, <iterable₁>, <iterable₂>, ..., <iterableₙ>) """
lst_1 = [1, 2, 3, 4, 5]
lst_2 = [10, 20, 30, 40, 50]
lst_3 = [100, 200, 300, 400, 500]
result = "{n} = {s}".format(n=" + ".join(map(str, [lst_1, lst_2, lst_3])),
                            s=list(map(lambda a, b, c: a + b + c, lst_1, lst_2, lst_3)))
print(result)  # [1, 2, 3, 4, 5] + [10, 20, 30, 40, 50] + [100, 200, 300, 400, 500] = [111, 222, 333, 444, 555]
