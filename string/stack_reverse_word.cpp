/** 题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。句子中单词以空格符隔开。
	为简单起见，标点符号和普通字母一样处理。
	例如输入“I am a student.”，则输出“student. a am I”。
	分析：由于编写字符串相关代码能够反映程序员的编程能力和编程习惯，与字符串相关的问题一直是程序员笔试、
	面试题的热门题目。本题也曾多次受到包括微软在内的大量公司的青睐。
	由于本题需要翻转句子，我们先颠倒句子中的所有字符。这时，不但翻转了句子中单词的顺序，
	而且单词内字符也被翻转了。我们再颠倒每个单词内的字符。由于单词内的字符被翻转两次，
	因此顺序仍然和输入时的顺序保持一致。
	还是以上面的输入为例子。翻转“I am a student.”中所有字符得到“.tneduts a ma I”，
	再翻转每个单词中字符的顺序得到“students. a am I”，正是符合要求的输出。
 */
#include <cstring>

#include <iostream>
#include <stack>
using std::cout;
using std::stack;
#include <assert.h>
static std::stack<int> s;

char* stack_reverse(char* sourcestat, char* deststat)
{
	// first word preindex is -1
	s.push(-1);
	int i = 0;
	while(sourcestat[i] != '\0') {
		if(' '==sourcestat[i]) {
			s.push(i); 
		}
		i++;
	}
	// word start every word
	int j;
	// init the end of dst 
	deststat[i] = '\0';
	int start = 0; 
	while(!s.empty()) {
		j = s.top();
		s.pop();
		memcpy(deststat+start, sourcestat+j+1,  i - j);
		start += i - j;
		deststat[start-1] = ' '; 
		i = j;
	}

	return deststat;
}

int main() {
	char source[] = "Hello, I am a student!";
	fprintf(stderr, "sizeof(\"%s\") = %ld\n", source, sizeof(source));
	char* dest = new char[sizeof(source)+1];
	fprintf(stderr, "%s\n", stack_reverse(source, dest));
	delete [] dest;

	char source2[] = "Yeah, your are beautiful!!!";
	fprintf(stderr, "sizeof(\"%s\") = %ld\n", source2, sizeof(source2));
	char* dest2 = new char[sizeof(source2)+1];
	fprintf(stderr, "%s\n", stack_reverse(source2, dest2));
	delete [] dest2;
	
	return EXIT_SUCCESS;
}