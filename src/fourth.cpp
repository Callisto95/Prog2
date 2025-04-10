static int add(int a, int b, int c = 10) {
	return a+b+c;
}

static void doSomething() {
	add(1,2);
}

int main() {
	int i = add(3.4, 4.7);
	int j = add(3.4, 4.7, 5);
	doSomething();
	
	return 0;
}
