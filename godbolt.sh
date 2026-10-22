curl -s -H "Content-Type: text/plain" --data-binary @demo.cpp \
	"https://godbolt.org/api/compiler/clang900/compile?options=-std=c%2B%2B11&filters=intel,demangle,labels,directives,commentOnly"
