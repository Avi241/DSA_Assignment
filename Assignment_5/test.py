import filecmp
  
f1 = "bst1_c.txt"
f2 = "op.txt"
  
# shallow comparison
result = filecmp.cmp(f1, f2)
print(result)
# deep comparison
result = filecmp.cmp(f1, f2, shallow=False)
print(result)