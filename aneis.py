
def main():
	tamanho = int(input())
	dic = {}
	for i in range(tamanho):
		var = int(input())
		if(var in dic):
			dic[var] = dic[var]+1
		else:
			dic[var] = 1
	
	maior = var
	for i in dic:
		if(dic[i]>dic[maior]):
			maior = i
			
	print(dic[maior])


main()
