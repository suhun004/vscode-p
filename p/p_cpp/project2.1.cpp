/* C++ 과제
 *  1. 함수를 사용할 것 (예: 입력받는 함수, 평균구하는 함수, 석차구하는 함수, 출력하는 함수 등)
 *  2. 함수 사용 시, 상황에 따라 값에 의한 전달 또는 참조에 의한 전달 기법을 선택하여 이용할 것
 *  3. 과목 수, 학생 수에 상관없이 일반적으로 처리할 수 있는 융통성 있는 프로그램으로 작성할 것
 *
 * 추가조건
 *  1. 클래스나 STL은 배우지 않았다고 함 (결국 C++보다는 C로 작성해야 함)
 *  2. 전역 변수를 사용하는 대신 참조(포인터) 전달을 하는 것으로 대신함
 */
#include <stdio.h>
#define NAME_MAX  20     // 이름 문자열 크기 제한
#define LINE_MAX  40     // 기타 입력 문자열 크기 제한
// 과목에 대한 타입.
typedef struct _subject_st {
char name[NAME_MAX]; // 이름
} subject;
// 학생에 대한 타입.
typedef struct _student_st {
char name[NAME_MAX]; // 이름
int number;          // 학번
int *score;          // 점수 배열
} student;
// 과목과 학생 목록 전체를 담는 타입.
typedef struct _school_st {
int st_cnt;          // 총 학생 수
int sb_cnt;          // 총 과목 수
    student *st_list;    // 학생 전체 목록
    subject *sb_list;    // 과목 전체 목록
} school;
// 입력은 뉴라인 문자까지 포함하여 읽어낸다.
// 따라서 비표준 flush 함수를 사용하지 않도록 한다.
int getline(char *s, int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
    s[i] = '\0';
  return i;
}
// 학생과 과목에 필요한 모든 메모리 공간을 초기화 한다.
void school_init(school *school) {
  int i;
  char buf[LINE_MAX];
  printf("학생 수를 입력하세요: ");
  getline(buf, LINE_MAX);
  sscanf(buf, "%d", &school->st_cnt);
  printf("과목 수를 입력하세요: ");
  getline(buf, LINE_MAX);
  sscanf(buf, "%d", &school->sb_cnt);
    school->st_list = new student[school->st_cnt];
    school->sb_list = new subject[school->sb_cnt];
  for (i = 0; i < school->st_cnt; i++) {
    student *st = &school->st_list[i];
    st->score = new int[school->sb_cnt];
  }
}
// 모든 동적 메모리 할당을 해제한다.
void school_free(school *school) {
  int i, j;
  for (i = 0; i < school->st_cnt; i++)
  delete[] school->st_list[i].score;
  delete[] school->st_list;
  delete[] school->sb_list;
}
// 모든 입력을 받는다.
void school_input(school *school) {
  char buf[LINE_MAX];
  int i, s;
  for (i = 0; i < school->sb_cnt; i++) {
  printf("%d번째 과목명을 입력하세요: ", i + 1);
  getline(school->sb_list[i].name, NAME_MAX);
  }
  for (i = 0; i < school->st_cnt; i++) {
    student *st = &school->st_list[i];
    printf("학생의 이름을 입력하세요: ");
    getline(st->name, NAME_MAX);
    printf("'%s' 학생의 학번을 입력하세요: ", st->name);
    getline(buf, LINE_MAX);
    sscanf(buf, "%d", &st->number);
    for (s = 0; s < school->sb_cnt; s++) {
      printf("'%s' 학생의 '%s' 점수를 입력하세요: ", st->name, school->sb_list[s].name);
      getline(buf, LINE_MAX);
      sscanf(buf, "%d", &st->score[s]);
    }
  }
}

// 학생의 과목 전체 평균을 구한다.
float student_avg(const school *school, const student *student) {
  float sum = 0;
  int i;
  for (i = 0; i < school->sb_cnt; i++)
    sum += student->score[i];
  return sum / school->sb_cnt;
}

// 주어진 과목의 학생 전체 평균을 구한다.
float subject_avg(const school *school, int subject) {
  float sum = 0;
  int i;
  for (i = 0; i < school->st_cnt; i++)
    sum += school->st_list[i].score[subject];
  return sum / school->st_cnt;
}

// 학생의 전체 평균을 기준으로 비교하는 함수
int student_sort_by_avg(const school *school, student *a, student *b) {
  float sub = student_avg(school, a) - student_avg(school, b);
  if (sub == 0) {
    return 0;
  } 
  else if (sub > 0) {
    return 1;
  } 
  else {
    return -1;
  }
}

// 내림차순으로 정렬한 포인터 항목들의 목록을 생성한다.
student **student_sorted_list(const school *_school, int (*compar)(const
school*, student*, student*)) {
    student **sorted_list = new student*[_school->st_cnt];
    student *st_list = _school->st_list;
    student *tmp;
  int cnt = _school->st_cnt;
  int sorted = 0;
  int i, j;
  for (i = 0; i < cnt; i++)
          sorted_list[i] = (student *)&st_list[i];
  while (!sorted) {
          sorted = 1;
  for (i = 1; i < cnt; i++) {
    if ((*compar)(_school, sorted_list[i], sorted_list[i - 1]) > 0) {
      tmp = sorted_list[i];
      sorted_list[i] = sorted_list[i - 1];
      sorted_list[i - 1] = tmp;
      sorted = 0;
      }
    }
  }
  return sorted_list;
}
// 각 학생에 대한 정보를 출력한다.
void school_output_student(school *school) {
    student **rank_list = student_sorted_list(school, &student_sort_by_avg);
float cur_avg = student_avg(school, rank_list[0]);
int cur_rank = 1;
int i, j;
for (i = 0; i < school->st_cnt; i++) {
        student *st = rank_list[i];
if (cur_avg > student_avg(school, st)) {
            cur_avg = student_avg(school, st);
            cur_rank = i + 1;
        }
printf("이름: %s\n", st->name);
printf("'%s'의 학번: %d\n", st->name, st->number);
printf("석차: %d\n", cur_rank);
for (j = 0; j < school->sb_cnt; j++) {
            subject *sb = &school->sb_list[j];
printf("'%s'의 '%s' 점수: %d\n", st->name, sb->name, st->score[j]);
        }
printf("'%s'의 평균 점수: %.2f\n", st->name, student_avg(school, st));
    }
delete[] rank_list;
}
// 각 과목에 대한 정보를 출력한다.
void school_output_subject(school *school) {
int i;
for (i = 0; i < school->sb_cnt; i++)
printf("'%s' 과목의 전체 평균: %.2f\n", 
               school->sb_list[i].name, subject_avg(school, i));
}

int  main()
{
    school school;
    school_init(&school);
    puts("\n== 정보 입력 ==\n");
    school_input(&school);
    puts("\n== 학생 정보 ==\n");
    school_output_student(&school);
    puts("\n== 과목 정보 ==\n");
    school_output_subject(&school);
    school_free(&school);

    return 0;
}