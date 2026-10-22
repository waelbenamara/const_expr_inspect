#include <cstdio>

template <int V> struct INTEGER {
	static constexpr int value() { return V; }
};

int input = 1;
struct INPUT {
	static int value() { return input; }
};

template <typename X, typename Y> struct ADD {
	static constexpr int value() { return X::value() + Y::value(); }
};

template <typename X> struct SQUARE {
	static constexpr int value() { return X::value() * X::value(); }
};

template <typename E, int V = E::value()> int evaluate(int) {
	return V;
}
template <typename E> int evaluate(...) {
	return E::value();
}

int constant() {
	return evaluate<ADD<SQUARE<INTEGER<3>>, INTEGER<4>>>(0);
}

int fallback() {
	return evaluate<ADD<SQUARE<INPUT>, INTEGER<4>>>(0);
}

int main() {
	std::printf("%d %d\n", constant(), fallback());
}
