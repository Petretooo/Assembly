#include<iostream>
using namespace std;


int abs(int value) {
	_asm {
		mov eax, value
		cmp eax, 0
		jge skip
		neg eax
		skip:
		mov value, eax
	}
}

int abs_module(int n) {
	_asm {
		mov eax, n
		cmp eax, 0
		jge skip
		neg eax
		skip:
	}
}
int power(int x) {
	_asm {
		mov eax, x
		mul eax
	}
}

int perimeter_rectangle(int a, int b) {
	_asm {
		mov eax, a
		add eax, a
		add eax, b
		add eax, b
	}
}

int area_rectangle(int a, int b) {
	_asm {
		mov eax, a
		mul b
	}
}

int perimeter_square(int a) {
	_asm {
		mov eax, a
		mov ecx, 4
		mul 4
	}
}

int area_square(int a) {
	_asm {
		mov eax, a
		mul a
	}
}

int perimater_triangle(int a, int b, int c) {
	_asm {
		mov eax, a
		add eax, b
		add eax, c
	}
}

int perimeter_triangle_second(int a) {
	_asm {
		mov eax, a
		mov ecx, 3
		mul ecx
	}
}

int perimeter_triangle_third(int a, int b) {
	int result = 0;
	int temp = 0;
	_asm {
		mov eax, a
		mul a
		mov ecx, eax
		mov eax, b
		mul b
		add eax, ecx
		mov temp, eax
		mov eax, a
		add eax, b
		mov result, eax
	}
	result += sqrt(temp);
	return result;
}



int triangle_perimeter_square(int b, int p) {
	int temp = 0;
	int result = 0;
	_asm {
		mov eax, b
		mul b
		mov ecx, eax
		mov eax, p
		mul p
		add eax, ecx
		mov temp, eax
		mov eax, b
		add eax, p
		mov result, eax
	}
	result += sqrt(temp)
		return result;
}

int area_triangle(int a, int b, int c) {
	int result = 0;
	_asm {
		mov eax, a
		add eax, b
		add eax, c
		mov ecx, 2
		mov edx, 0
		div ecx
		mov ecx, eax
		sub ecx, a
		mul ecx
		add ecx, a
		sub ecx, b
		mul ecx
		add ecx, b
		sub ecx, c
		mul ecx
		mov result, eax
	}
	return sqrt(result);
}




int area_t(int a, int b, int c) {
	int result = 0;
	_asm {
		mov eax, a
		add eax, b
		add eax, c
		mov ecx, 2
		mov edx ,0
		div ecx
		mov ecx, eax
		sub ecx, a
		mul ecx
		add ecx, a
		sub ecx, b
		mul ecx
		add ecx, b
		sub ecx, c
		mul ecx
		mov result, eax
	}
	return sqrt(result);
}

int main() {
	cout << abs_module(-5) << endl;
	cout << power(5) << endl;
	cout << perimeter_rectangle(5, 6) << endl;
	cout << area_rectangle(5, 6) << endl;
	cout << perimeter_square(7) << endl;
	cout << area_square(6) << endl;
	cout << perimater_triangle(2, 3, 4) << endl;
	cout << perimeter_triangle_second(4) << endl;
	cout << perimeter_triangle_third(3, 4) << endl;
	cout << area_triangle(2, 3, 4) << endl;
}