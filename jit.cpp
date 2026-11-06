#include <cstdio>
#include <string>

template <int V> struct INTEGER {
	static constexpr int value() { return V; }
};

template <typename X, typename Y> struct ADD {
	static constexpr int value() { return X::value() + Y::value(); }
};

template <typename E> int run(int x) {
	constexpr int v = E::value(); // computed by the compiler
	return x + v;                 // computed at run time
}

int (*f)(int);

template <typename E> [[clang::jit]] void compile() {
	f = run<E>;
}

int main() {
	std::string program = "ADD<INTEGER<3>, INTEGER<4>>"; // known only at run time
	compile<program>();
	std::printf("x + %s with x = 5: %d\n", program.c_str(), f(5));
}
