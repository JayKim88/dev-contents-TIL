# Javascript Question

<h2>1. Shallow Copy 와 Deep Copy</h2>

자바스크립트에서 자료형은 아래와 같이 크게 기본형(Primitive Value) 과 참조형(Reference Type) 2가지로 나눌 수 있다.

기본형 (Primitive Value)

- Boolean
- Null
- Undefined
- Number
- String

참조형(Reference Type)

- Object(배열, 일반 객체, 함수)

이때 기본 자료형의 경우는 아래의 코드에서 볼 수 있듯이 copy 의 value 를 변경하더라도 string 의 value 엔 영향을 주지 않는다.

```js
let string = "hello";
let copy = string;
console.log(copy); // 'hello'
let copy = "hi";
console.log(string); // 'hi'
```

하지만, 참조형의 경우 ref 배열의 항목을 변경하면 array 의 항목도 변하는 것을 알 수 있다.
이는 참조형은 다른 변수에 대입할 때 값을 복사하는 게 아니라 참조(메모리의 주소)를 복사하기 때문에 발생하는 현상이다.

```js
let array = ["a", "b", "c"];
let ref = array;
ref[0] = "d";
console.log(array); // ['d', 'b', 'c']
```

위와 같은 특성으로 인해 참조형 copy 는 **shallow copy(얕은 복사)** 와 **deep copy(깊은 복사)** 가 있다.
shallow copy는 가장 상위 객체만 새로 생성되고 내부 객체들은 참조 관계인 경우를 의미하고 deep copy는 내부 객체까지 모두 새로 생성된 것을 의미한다.

### **Shallow Copy 코드**

같은 주소를 보고 있기 때문에 복사한 variable 의 항목을 변경하면 원본의 값도 변경된다.

```js
let employeeDetailsOriginal = {
  name: "JayKim",
  age: 30,
  profession: "software Enginner",
};
let employeeDetailsDuplicate = employDetailsOriginal;
//Shallow Copy

employDetailsDuplicate.name = "NameChanged";
//This statement will also change name from employeeDetailsOriginal,
//since we have a shallow copy, or a reference to let employeeDetailsOriginal.
//This means, you’re losing the original data as well.
```

- 장점 : 같은 객체를 공유하므로 메모리를 절약하고, 빠른 장점이 존재한다. 참조에 의한 호출(Call by Reference)에서 얕은 복사가 이루어 지는 이유 중 하나이다.

- 단점 : 두개 이상의 객체가 같은 대상을 가리키고 있기 때문에, 의도치 않게 여러 개의 객체가 동시에 수정될 수 있다.

### **Deep Copy 코드**

객체 내부 항목들에 value 가 직접 할당되는 깊은 복사이기 때문에 복사한 variable 의 항목이 변경되더라도 원본 값엔 영향을 주지 않는다.

```js
let employDetailsDuplicate = {
  name: employDetailsOriginal.name,
  age: employDetailsOriginal.age,
  Profession: employDetailsOriginal.Profession,
};
//Deep copy
```

- 장점 : 여러 객체가 동시에 수정되는 일이 발생하지 않아 안전하다.

- 단점 : 객체 생성 비용이 비싸며, 메모리를 많이 점유한다.

<img src='./image/1.png'>

<h2> 2. 이벤트 루프와 태스크 큐(비동기 처리하는 프로세스)</h2>

브라우저의 동작을 보면 태스크가 동시에 처리되는 것처럼 느껴지는데, 이러첨 자바스크립트의 동시성(concurrency) 을 지원하는 것이 이벤트 루프(event loop)이다. 이벤트 루프는 브라우저에 내장되어 있는 기능이다.

<img src='./image/2-1.png' width="600px">

- 힙: 객체가 저장되는 메모리 공간으로 콜 스택의 요소인 실행 컨텍스트는 힙에 저장된 객체를 참조한다. 저장할 객체는 원시 값과 달리 크기가 정해져 있지 않기 때문에 할당해야 할 메모리 공간의 크기를 런타임에 동적으로 할당해야 한다. 즉, 메모리 공간인 힙은 구조화 되어 있지 않다.
- 태스크 큐: 비동기 함수의 콜백 함수 또는 이벤트 핸들러가 일시적으로 보관되는 영역
- 이벤트 루프: 콜 스택과 태스크 큐를 반복해서 확인하고, 콜 스택이 비어 있고 태스크 큐에 대기 중인 함수가 있으면 이 이벤트 루프가 순차적으로 태스크 큐에서 콜 스택으로 함수를 이동 시킨다. 즉, 태스크 큐의 함수들은 비동기 처리 방식으로 동작하는 것이다.

비동기 처리에서 소스코드의 평가와 실행을 제외한 모든 처리는 자바스크립트 엔진을 구동하는 환경인 **브라우저 또는 Node.js** 가 담당한다.

- 자바스크립트 엔진: 비동기로 동작하는 setTimeout 의 콜백 함수의 평가와 실행 담당

- 브라우저 || Node.js: **호출 스케쥴링을 위한 타이머 설정과 콜백 함수 태스크 큐에 등록 담당**. 이를 위해 브라우저 환경이 태스크 큐와 이벤트 루프를 제공한다.

## [Here, You can test How Event loop works!!!](http://latentflip.com/loupe/?code=JC5vbignYnV0dG9uJywgJ2NsaWNrJywgZnVuY3Rpb24gb25DbGljaygpIHsKICAgIHNldFRpbWVvdXQoZnVuY3Rpb24gdGltZXIoKSB7CiAgICAgICAgY29uc29sZS5sb2coJ1lvdSBjbGlja2VkIHRoZSBidXR0b24hJyk7ICAgIAogICAgfSwgMjAwMCk7Cn0pOwoKY29uc29sZS5sb2coIkhpISIpOwoKc2V0VGltZW91dChmdW5jdGlvbiB0aW1lb3V0KCkgewogICAgY29uc29sZS5sb2coIkNsaWNrIHRoZSBidXR0b24hIik7Cn0sIDUwMDApOwoKY29uc29sZS5sb2coIldlbGNvbWUgdG8gbG91cGUuIik7!!!PGJ1dHRvbj5DbGljayBtZSE8L2J1dHRvbj4%3D)

### 비동기처리 프로세스 예제

<img src='./image/2-2.png' width="600px">

1. 전역 코드 평가 → 전역 실행 컨텍스트 생성 → 콜 스택 푸시

2. setTimeout 함수 실행 컨텍스트 생성 → 콜 스택 푸시

3. 브라우저가 setTimeout 함수의 콜백 함수를 호출 스케쥴링(타이머 설정) 하고, 이 setTimeout 함수는 콜 스택에서 팝 된다.

4. 병행 처리

   1. 브라우저: 타이머 만료시 콜백함수 foo 를 태스크 큐에 푸시한다.
   2. 자바스크립트 엔진: bar 함수 실행 컨텍스트 생성 → 콜스택 푸시 → 현재 실행 중인 실행 컨텍스트 → bar 함수 종료 → 콜스택에서 팝

5. 전역 코드 실행 종료 → 전역 실행 컨텍스트 팝

6. 이벤트 루프에 의해 콜스택 비어 있음이 감지 → 태스크 큐의 콜백함수 foo 가 콜스택에 푸시 되어 실행된다. → foo 팝

**자바스크립트 엔진은 싱글 스레드로 동작하고, 브라우저는 멀티 스레드로 동작하기 때문에 비동기 처리가 가능하다. 즉, 브라우저와 자바 스크립트 엔진이 협력하여 비동기 함수를 실행하는 것이다.**