#pragma once

/* Game의 모든 것을 총괄하기에 여기서 플레이어를 관리한다고 하자.
우선 Game과 Player의 관계를 살펴야한다.

is - a / has - a 관계를 놓고 보았을 때,
(상속관계) / (포함관계)
Game이 Player인가? -> 말이 안된다.
Game이 Player를 가졌는가? -> 어느정도 말이 된다. 
고로 포함관계로 설계를 해보자.

그럼 관리하는 부분을 어디에 생성해야 할까?
-> private: 안에 생성해야 한다. */
class Player;
class Field;

class Game
{
public:
    Game();
    ~Game();

    void Init();
    void Update();

    void CreatePlayer();

private:
    /* 포함관계를 설계할때 
    맴버 클래스로 생성하는가 / 포인터로 생성하는가 이는 확연한 차이를 보인다.
    - 멤버 클래스로 생성 : 이는 의존성이 매우 강해진다.
    Game이 생성되기 위해서는 Player가 반드시 있어야 한다.
    그리고 방대한 양의 데이터를 복사하는 개념이 추가되어 부하를 일으킬 수 있다. */
    // Player player;
    
    /* - 포인터로 생성 : 생성된 Player의 주소값을 가지고 접근하는 방법으로 
    생성되는데 맴버 클래스보다 부하가 현저히 적게 일어난다. 
    의존성이 맴버 클래스에 비해 매우 낮다. */
    Player* _player;
    Field* _field;
    /* 포인터로 생성을 하게 된다면 이는 의존성이 매우 낮기에 
    굳이 #include를 하지 않아도 된다.
    
    하지만 Player는 Game.h에 존재하지 않는 클래스이기에 에러가 발생하는데 
    이때는 전방선언을 통해 해결해주면 된다. */

};

