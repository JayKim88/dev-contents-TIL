/* 
삼각형 판별하기

길이가 서로 다른 A, B, C 세 개의 막대 길이가 주어지면 이 세 막대로 삼각형을 만들 수 있 으면 “YES"를 출력하고, 만들 수 없으면 ”NO"를 출력한다.

▣ 입력설명
첫 번째 줄에 100이하의 서로 다른 A, B, C 막대의 길이가 주어진다.
▣ 출력설명
첫 번째 줄에 “YES", "NO"를 출력한다.
▣ 입력예제 1 6 7 11
▣ 출력예제 1 YES
▣ 입력예제 1 13 33 17
▣ 출력예제 1 NO
*/


function checkIfTriangle(n1, n2, n3) {
  let result = "It's triangle";
  let findMax;
  let sum = n1 + n2 + n3;

  if (n1 > n2) {
    findMax = n1;
  } else {
    findMax = n2;
  }
  if (n3 > findMax) findMax = n3;

  if (sum <= 2 * findMax) result = "nope";

  return result;
}

console.log(checkIfTriangle(12, 15, 2));

/* solution example
function solution(a, b, c){
            let answer="YES", max;
            let tot=a+b+c;
            if(a>b) max=a;
            else max=b;
            if(c>max) max=c;
            if(tot-max<=max) answer="NO"; 
            return answer;
        }

console.log(solution(13, 33, 17));
*/


*/
