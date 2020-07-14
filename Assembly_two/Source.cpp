#include<iostream>
using namespace std;
#include <array>


int factorial(int a) {
	_asm {
		mov eax, 1; зареждаме eax s 1, защото започваме от единица
		mov ecx, 1; зареждаме ecx с 1, защото това ще ни брояча

		for:
		imul eax, ecx; умножаме eax с брояча
			inc ecx; увеличаме с единица брояча
			cmp a, ecx; сравнение
			jge for; ако е "а" по-голямо или равно на брояча продължаваме 
	}

	/*
		5!- 1 * 2 * 3 * 4 * 5 = 120
		при първото завъртане умножаваме 1 * 1 = 1
		при второто завъртане вече сме увеличили брояча с единица и умножаваме стойността с брояча 1 * 2 = 2
		на трето завъртане отново с единица увеличаваме брояча и умножаваме стойността 2 * 3 = 6
		и така докато брояча стане 5, при четвърто завъртане 6 * 4 = 24 и при последно завъртане, защото
		вече брояча ще е станал 5, то тогава 24 * 5 = 120, и ще спре, защото вече брояча е станал колкото подаденото число - а = 5!
	
	*/
}

int do_negative_tests(int a) {
	char p1;
	short p2;
	int p4;
	_asm {
		movsx eax, p1
			mov byte ptr p2, al
			mov byte ptr p4, ah
			mov ax, word ptr p4
			mov eax, dword ptr p4
	}
	return a;
}

int avg_int(int a, int b, int c) {
	_asm {
		movsx eax, a;
		add eax, b;
		add eax, c;
		mov ecx, 3;
		mov edx, 0;
		div ecx;
	}
}
short avg_short(short a, short b, short c) {
	_asm {
		movsx ax, a;
		add ax, b;
		add ax, c;
		mov cx, 3;
		mov dx, 0;
		div cx;
	}
}

int sgn(int i) {//return 1 / 0 / -1
	_asm {
		mov eax, 1
		cmp eax, i
		jle return
		mov eax, 0
		cmp eax, i
		je return
		mov eax, -1
		return:
	}
}

int positive(int a, int b, int c) {
	_asm {
		mov eax, 0
		cmp eax, a
		jg return
		cmp eax, b
		jg return;
		cmp eax, c
		jg return
		mov eax, 1
		return:
	}
}

int power(int number, int powers) {
	_asm {
		mov eax, number
		mov ecx, 1
		for:
		mul number
		inc ecx
		cmp ecx, powers
		jnae for
	}
}

int n_m(int a, int b) {
	_asm {
		mov eax, 1
		mov ecx, 1
		for:
		imul eax, ecx
			inc ecx
			cmp a, ecx
		jge for

		mov ebx, eax

		mov eax, 1
		mov ecx, 1
		for_one:
		imul eax, ecx
			inc ecx
			cmp b, ecx
		jge for_one

		mov edx, 0
		div ebx
	}
}


int compare_two(int a, int b) {
	_asm {
		mov eax, 0
		mov ebx, a
		cmp ebx, b
		je return
		jl jump
		mov eax, 1
		jmp return
		jump:
		mov eax, -1
		return:
	}
}

int compare_three(int a, int b, int c) {//!
	int br = 0;
	int sum = 0;
	
	_asm {
		mov ebx, a
		cmp ebx, 0
		jle nega; a<=0
			inc br
			mov sum, ebx
			nega:
		mov ebx, b
			cmp ebx, 0
			jle negb; b <= 0
			inc br
			add sum, ebx
			negb:
		mov ebx, c
			cmp ebx, 0
			jle negc; c <= 0
			inc br
			add sum, ebx
			negc:
	}
}

int compare_three_second(int a, int b, int c) {
	int count = 0;
	int sum = 0;
	_asm {
		mov ebx, a
		cmp ebx, 0
		jle labelA
			inc count
			mov sum, ebx
			labelA:
		mov ebx, b
			cmp ebx, 0
			jle labelB
			inc count
			add sum, ebx
			labelB:
		mov ebx, c
			cmp ebx, 0
			jle labelC
			inc count
			add sum, ebx
			labelC:
	}
}


int max_number(int a, int b, int c) {
	_asm {
		mov eax, a
		cmp eax, b
		jg  greater_one
		mov eax, b
		greater_one:
		cmp eax, c
		jg greater__one
		mov eax, c
		greater__one:
	}
}


int factorial_one(int num) {
	_asm {
		mov eax, 1
		mov ecx, 1
		for:
		mul ecx
		inc ecx
		cmp num, ecx
		jge for
	}
}

int multiples(int n) {
	int arr[10];
	_asm{
		mov eax, 0
		mov eax, n
		mov ecx, 0
		for:
		mov[arr + 4 * ecx], eax
		add eax, n
		inc ecx
		cmp ecx, 10
		jl for
	}
	int length = *(&arr + 1) - arr;

	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
}

int array_full(int n) {
	int arr[20];
	_asm {
		mov eax, 0
		mov eax, n
		mov ecx, 0
		for:
		mov[arr + 4 * ecx], eax
		add eax, n
		inc ecx
		cmp ecx, 20
		jl for
	}

	int length = *(&arr + 1) - arr;
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
}



int array_one(int n) {
	int arr[15];
	_asm {
		mov eax, 0
		mov eax, n
		mov ecx, 0
		label_one:
		mov[arr + 4 * ecx], eax
		add eax, n
		inc ecx
		cmp ecx, 15
		jl label_one
	}
	int length = *(&arr + 1) - arr;
	for (int i = 0; i < length; i++) {
		cout << arr[i] <<" ";
	}
}

int fibonacci(int n) {
	int arr[10];
	arr[0] = 1;
	arr[1] = 1;
	_asm {
		mov ecx, 0
		cycle:
		mov eax, [arr + 4 * ecx]
		add eax, [arr + 4 + 4 * ecx]
		mov[arr + 8 + 4 * ecx], eax
		inc ecx
		cmp ecx, n
		jle cycle
	}
}



int fibonacci_one(int n) {
	int arr[15];
	arr[0] = 1;
	arr[1] = 1;
	_asm {
		mov ecx, 0
		for:
		mov eax, [arr + 4 * ecx]
		add eax, [arr + 4 + 4 * ecx]
		mov [arr + 8 + 4 * ecx], eax
		inc ecx
		cmp ecx, n
		jle for
	}
}



int factorial_third(int n) {
	_asm {
		mov eax, 1
		mov ecx, 1
		for:
		mul ecx
		inc ecx
		cmp ecx, n
		jle for
	}
}

int factorial_fourth(int n) {
	_asm {
		mov eax, 1
		mov ecx, 1
		for:
		mul ecx
		inc ecx
		cmp ecx, n
		jge for
	}
}

int fibonacci_thirds(int n) {
	int arr[15];
	arr[0] = 1;
	arr[1] = 1;
	_asm {
		mov ecx, 0
		for:
		mov eax, [arr + 4 * ecx]
		add eax, [arr + 4 +4 * ecx]
		mov [arr +8 +4 * ecx], eax
		inc ecx
		cmp ecx, 15
		jle for
	}
}

int full_the_array(int num) {
	int arr[15];
	_asm {
		mov eax, num
		mov ecx, 0
		for:
		mov [arr + 4 * ecx]
		add num
		inc ecx
		cmp ecx, num
		jl for
	}
}

int main() {


	cout << factorial(5) << endl;
	cout << sgn(-5) << endl;
	cout << positive(1, 4, 6) << endl;
	cout << power(2, 3) << endl;
	cout << n_m(5, 15) << endl;
	cout << compare_two(2, 3) << endl;
	cout << compare_three(1, 2, 3) << endl;
	cout << max_number(1, 2, 3) << endl;
	cout << compare_three_second(2, 4, 6) << endl;
	cout << factorial_one(5) << endl;
	cout << multiples(5) << endl;
	cout << array_one(10) << endl;
	cout << fibonacci(4) << endl;
	cout << factorial_third(5) << endl;
}