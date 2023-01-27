#include <iostream>
#include "Test1.h"
using namespace std;

/* int main()이 있는 파일의 경우, 프로젝트 파일의 총 망라 라고 볼 수 있다. 
그렇기에 이를 간단하게 작성하고 최대한 포함하는 관계를 형성하는게 중요하다.

기존의 void function() 에 해당하는 부분(선언부)은 xxxx.h (헤더파일)에 보관

void function() { logic } 에 해당하는 부분(구현부)은 xxxx.cpp 에 보관 */

int main() {

	/* 다음과 같이 Test_1() 이라는 함수를 main() 함수 안에서 사용한다고 한다면 
	이제는 main.cpp 파일 안에 선언부와 구현부를 작성하지 않고 이를 파일에 각각 나누어 작성한 뒤,

	선언부를 작성한 xxx.h 파일을 #include "xxxx.h" 를 통해 포함하는 관계를 형성해주면 된다.
	
	#include "Test_1.h"

	위의 코드를 통해 이제는 더이상 main.cpp 파일 안에 선언부를 작성하지 않아도 된다. (간결성 보장)

	그럼 여기서 우리는 한가지 의문이 생길 수 있다. -> 우리는 분명 선언부에 해당하는 파일만 include 했을 뿐인데 왜 작동하는 것인가?

	이유는 간단하다. 

	xxx,h 를 포함하고 있는 xxx.cpp에서 실행에 필요한 구현부 또한 가지고 있기 때문에 실행이 가능한 것이다. */
	Test_1();
}