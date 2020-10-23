lst = [1, 2, 3, 'Alice', 'Alice']
indices = [i for i in range(len(lst)) if lst[i]=='Alice']
print(indices)
