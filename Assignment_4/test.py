import filecmp
  
f1 = "stack.txt"
f2 = "output.txt"
  
# shallow comparison
result = filecmp.cmp(f1, f2)
print(result)
# deep comparison
result = filecmp.cmp(f1, f2, shallow=False)
print(result)