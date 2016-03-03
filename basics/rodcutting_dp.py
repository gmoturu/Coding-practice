price=[1,5,8,9,10,17,17,20,24,30]
splitpipe=[(0,1)]
maxprice=[1]
psize=input('')
for i in range(2,psize+1):
	for j in range(0,i/2+1):
		if(j==0):
			maxprice.append(price[i-1])
			splitpipe.append((0,i))
		else:
			temp=maxprice[j-1]+maxprice[i-j-1]
			if(temp>maxprice[i-1]):
				maxprice[i-1]=temp
				splitpipe[i-1]=(j,i-j)
print maxprice[psize-1]
print splitpipe
