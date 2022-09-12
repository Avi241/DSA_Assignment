import filecmp
  
f1 = "radix1.txt"
f2 = "radix.txt"
  
# shallow comparison
result = filecmp.cmp(f1, f2)
print(result)
# deep comparison
result = filecmp.cmp(f1, f2, shallow=False)
print(result)