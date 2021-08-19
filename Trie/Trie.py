

##the dictionary of letters to be used. Default is [a-z, A-Z]. 
DICTIONARY = {}

class TrieNode:

	##node class for Trie
	def __init__(self, char):
		##children is a dictionary of letter, node pairs
		self.children = {}
		##letter is the current nodes letter
		self.char = char
		##end indicates if node is the end of the word
		self.end = False
		
		#keep the full word in leaf nodes
		self.word = ''








class Trie:
	def __init__(self):
		self.root = TrieNode('')
		self.words = []
		self.numWords = 0

	
	def insert(self, key):
		#set the node to the root
		node = self.root
		
		#insert the key into the trie 
		c = ''
		for i in range(len(key)):
			c=key[i]
			if c not in node.children.keys():
				node.children[c] = TrieNode(c)
			##set the node to the child
			node = node.children[c]
		
		node.end = True
		node.word = key[:]
		self.numWords+=1
	
	##returns true if the word exists, else false
	def exists(self, word):
		node = self.root
		c = ''
		for i in range(len(word)):
			c = word[i]
			#if c is not in any of the children, then the word does not exist in the trie
			if c not in node.children.keys():
				return False 
			
			#set the node to the child, which is the node containing c
			node = node.children[c]
		##if found, return true
		return node.end  
	
	##gets all words in the trie with the same prefix as 'prefix'
	def getPrefixed(self, prefix):
		
		node = self.root 
		for i in range(len(prefix)):
			#make sure the prefix exists
			c = prefix[i]
			if c not in node.children.keys():
				return None 
			node = node.children[c]
		
		self.__getPrefixedHelper(node)


	##helper function that does the recursion
	def __getPrefixedHelper(self, node):
		
		##if at a leaf, then return
		if node.end:
			self.words.append(node.word)
			 
		for child in node.children.values():
			self.__getPrefixedHelper(child)
		

	def __len__(self):
		return self.numWords

	##clears all the strings from self.words
	def clearWords(self):
		self.words.clear()
	
		

			



if __name__ == "__main__":

	f = open("american-english-no-accents.txt", "r")
	content = f.readlines()
	words = []
	
	for word in content:
		words.append(word.rstrip())
	
	trie = Trie()
	print(len(words))
	for word in words:
		trie.insert(word)

	trie.getPrefixed("Adven")
	print(trie.words)

	




			
			
		

