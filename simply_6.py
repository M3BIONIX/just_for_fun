name_1=input("Enter the Name ")
i=0
name_1=name_1.lower()
while i<len(name_1):
 if name_1[i]=='a':
    name_1=name_1.replace(name_1[i],'')
 elif name_1[i]=='e':
   name_1=name_1.replace(name_1[i],'')
 elif  name_1[i]=='i':  
   name_1=name_1.replace(name_1[i],'')
 elif  name_1[i]=='o': 
   name_1=name_1.replace(name_1[i],'')
 elif  name_1[i]=='u':
   name_1=name_1.replace(name_1[i],'')
 else:
   i=i
i=i+1
 
print(name_1)
