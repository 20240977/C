#include <stdio.h>
#include <time.h>

int main() {
    
    time_t now = time(NULL); 
    struct tm currentDate;
    localtime_s(&currentDate, &now); 

    
    int year, month, day;
    printf("��ǥ ��¥�� �Է��ϼ��� (YYYY MM DD): ");
    if (scanf("%d %d %d", &year, &month, &day) != 3) {
        printf("�߸��� �Է��Դϴ�. YYYY MM DD �������� �Է��ϼ���.\n");
        return 1;
    }

    
    struct tm targetDate = { 0 };
    targetDate.tm_year = year - 1900; 
    targetDate.tm_mon = month - 1;   
    targetDate.tm_mday = day;

    
    time_t targetTime = mktime(&targetDate);

    if (targetTime == -1) {
        printf("��ȿ���� ���� ��¥�Դϴ�. �ùٸ� ��¥�� �Է��ϼ���.\n");
        return 1; 
    }

    
    double differenceInSeconds = difftime(targetTime, now);

    
    int differenceInDays = (int)(differenceInSeconds / (60 * 60 * 24));

    
    if (differenceInDays > 0) {
        printf("D-%d �Դϴ�.\n", differenceInDays);
    }
    else if (differenceInDays == 0) {
        printf("������ D-Day �Դϴ�!\n");
    }
    else {
        printf("D+%d (�̹� ���� ��¥�Դϴ�).\n", -differenceInDays);
    }

    return 0;
}
	/*
    �ð�ó�� �ǽ�

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
