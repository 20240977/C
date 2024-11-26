#include <stdio.h>
#include <time.h>

int main() {
    
    time_t now = time(NULL); 
    struct tm currentDate;
    localtime_s(&currentDate, &now); 

    
    int year, month, day;
    printf("목표 날짜를 입력하세요 (YYYY MM DD): ");
    if (scanf("%d %d %d", &year, &month, &day) != 3) {
        printf("잘못된 입력입니다. YYYY MM DD 형식으로 입력하세요.\n");
        return 1;
    }

    
    struct tm targetDate = { 0 };
    targetDate.tm_year = year - 1900; 
    targetDate.tm_mon = month - 1;   
    targetDate.tm_mday = day;

    
    time_t targetTime = mktime(&targetDate);

    if (targetTime == -1) {
        printf("유효하지 않은 날짜입니다. 올바른 날짜를 입력하세요.\n");
        return 1; 
    }

    
    double differenceInSeconds = difftime(targetTime, now);

    
    int differenceInDays = (int)(differenceInSeconds / (60 * 60 * 24));

    
    if (differenceInDays > 0) {
        printf("D-%d 입니다.\n", differenceInDays);
    }
    else if (differenceInDays == 0) {
        printf("오늘은 D-Day 입니다!\n");
    }
    else {
        printf("D+%d (이미 지난 날짜입니다).\n", -differenceInDays);
    }

    return 0;
}
	/*
    시간처리 실습

    #include <stdio.h>
    #include <time.h>

    int main(int argc, char* argv[]){

	time_t current;
	struct tm* timeinfo;

	int year, month, day;
	char* WEEK[] = { "sun", "mon", "tue", "wed", "thu", "fri", "sat" };

	printf("Enter YYYY MM DD : ");
	scanf("%d %d %d", &year, &month, &day);

	current = time(NULL);
	timeinfo = localtime(&current);

	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	mktime(timeinfo);

	printf("%d %d %d -> %s\n", year, month, day, WEEK[timeinfo->tm_wday]);
    }
	*/
