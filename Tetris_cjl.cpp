//#include <stdio.h>
//#include <windows.h>
//#include <stdlib.h>
//#include <time.h>
//#include <conio.h>
//#define BOARD_HEIGHT 20 // ┃개수
//#define BOARD_WIDTH 10  // ━개수
//#define BOARD_X 4 //보드 열 x좌표
//#define BOARD_Y 2 //보드 행 y좌표
//#define CBLOCK_X 13 //cjl:무슨 변수냐..
//#define CBLOCK_Y 2
//#define DELAY 100//지연
//#define RAND 4//난수
//#define LEFT 75
//#define RIGHT 77
//#define UP 72
//#define DOWN 80
//#define SPACE 32
//int static score = 0; //게임점수
//int static level = 1; //게임레벨
//int static speed = 180;
//int curX, curY; //콘솔커서
//int board[BOARD_HEIGHT + 1][BOARD_WIDTH + 2] = { 0, };
////2차원 배열로 테트리스 블록을 구현
//int block[][4][4] = { //cjl:4x4 2차원 배열로 도형표시-> 2차원 배열의 배열->3차원 배열
//	/*■
//	■■■*/
//	{
//	 { 0,0,0,0 },
//	 { 1,0,0,0 },
//	 { 1,1,1,0 },
//	 { 0,0,0,0 } },
//
//	{
//	 { 0,0,1,0 },
//	 { 0,0,1,0 },
//	 { 0,1,1,0 },
//	 { 0,0,0,0 } },
//
//	{
//	 { 1,1,1,0 },
//	 { 0,0,1,0 },
//	 { 0,0,0,0 },
//	 { 0,0,0,0 } },
//
//	{
//	 { 1,1,0,0 },
//	 { 1,0,0,0 },
//	 { 1,0,0,0 },
//	 { 0,0,0,0 } },
//
//	 /* 두 번째 블록
//		 ■
//		 ■■■     */
//
//	 {
//	  { 0, 0, 0, 0 },
//	  { 0, 0, 1, 0 },
//	  { 1, 1, 1, 0 },
//	  { 0, 0, 0, 0 } },
//
//	 {
//	  { 0, 1, 1, 0 },
//	  { 0, 0, 1, 0 },
//	  { 0, 0, 1, 0 },
//	  { 0, 0, 0, 0 } },
//
//	 {
//	  { 1, 1, 1, 0 },
//	  { 1, 0, 0, 0 },
//	  { 0, 0, 0, 0 },
//	  { 0, 0, 0, 0 } },
//
//	 {
//	  { 1, 0, 0, 0 },
//	  { 1, 0, 0, 0 },
//	  { 1, 1, 0, 0 },
//	  { 0, 0, 0, 0 } },
//
//	  /* 세 번째 블록
//	  ■
//	  ■■■    */
//	   {
//		{ 0, 0, 0, 0 },
//		{ 0, 1, 0, 0 },
//		{ 1, 1, 1, 0 },
//		{ 0, 0, 0, 0 } },
//
//	   {
//		{ 0, 0, 0, 0 },
//		{ 0, 1, 0, 0 },
//		{ 1, 1, 0, 0 },
//		{ 0, 1, 0, 0 } },
//
//	   {
//		{ 0, 0, 0, 0 },
//		{ 0, 0, 0, 0 },
//		{ 1, 1, 1, 0 },
//		{ 0, 1, 0, 0 } },
//
//	   {
//		{ 0, 0, 0, 0 },
//		{ 0, 1, 0, 0 },
//		{ 0, 1, 1, 0 },
//		{ 0, 1, 0, 0 } },
//
//	/* 네 번째 블록
//		■■■■   */
//	   {
//		{ 0, 1, 0, 0 },
//		{ 0, 1, 0, 0 },
//		{ 0, 1, 0, 0 },
//		{ 0, 1, 0, 0 } },
//
//	   {
//		{ 0, 0, 0, 0 },
//		{ 0, 0, 0, 0 },
//		{ 1, 1, 1, 1 },
//		{ 0, 0, 0, 0 } },
//
//	   {
//		{ 0, 1, 0, 0 },
//		{ 0, 1, 0, 0 },
//		{ 0, 1, 0, 0 },
//		{ 0, 1, 0, 0 } },
//
//	   {
//		{ 0, 0, 0, 0 },
//		{ 0, 0, 0, 0 },
//		{ 1, 1, 1, 1 },
//		{ 0, 0, 0, 0 } },
//
//	/* 다섯 번째 블록
//		■■
//		■■      */
//	   {
//		{ 1, 1, 0, 0 },
//   	    { 1, 1, 0, 0 },
//		{ 0, 0, 0, 0 },
//		{ 0, 0, 0, 0 } },
//
//	   {
//		{ 1, 1, 0, 0 },
//		{ 1, 1, 0, 0 },
//		{ 0, 0, 0, 0 },
//		{ 0, 0, 0, 0 } },
//
//	   {
//		{ 1, 1, 0, 0 },
//		{ 1, 1, 0, 0 },
//		{ 0, 0, 0, 0 },
//		{ 0, 0, 0, 0 } },
//
//	   {
//		{ 1, 1, 0, 0 },
//		{ 1, 1, 0, 0 },
//		{ 0, 0, 0, 0 },
//		{ 0, 0, 0, 0 } },
//
//		/* 여섯 번째 블록
//		   ■■
//		  ■■      */
//	   {
//		{ 0, 0, 0, 0 },
//		{ 0, 1, 1, 0 },
//		{ 1, 1, 0, 0 },
//		{ 0, 0, 0, 0 } },
//
//		{
//		 { 0, 1, 0, 0 },
//		 { 0, 1, 1, 0 },
//		 { 0, 0, 1, 0 },
//		 { 0, 0, 0, 0 } },
//
//		{
//		 { 0, 0, 0, 0 },
//		 { 0, 1, 1, 0 },
//		 { 1, 1, 0, 0 },
//		 { 0, 0, 0, 0 } },
//
//		{
//		 { 0, 1, 0, 0 },
//		 { 0, 1, 1, 0 },
//		 { 0, 0, 1, 0 },
//		 { 0, 0, 0, 0 } },
//
//	/* 일곱 번째 블록
//		■■
//		 ■■    */
//	    {
//		 { 0, 0, 0, 0 },
//		 { 1, 1, 0, 0 },
//		 { 0, 1, 1, 0 },
//		 { 0, 0, 0, 0 } },
//
//		{
//		 { 0, 0, 1, 0 },
//		 { 0, 1, 1, 0 },
//		 { 0, 1, 0, 0 },
//		 { 0, 0, 0, 0 } },
//
//		{
//		 { 0, 0, 0, 0 },
//		 { 1, 1, 0, 0 },
//		 { 0, 1, 1, 0 },
//		 { 0, 0, 0, 0 } },
//
//		{
//	   	 { 0, 0, 1, 0 },
//	 	 { 0, 1, 1, 0 },
//		 { 0, 1, 0, 0 },
//		 { 0, 0, 0, 0 } },
//
//};
//
////콘솔화면 커서 깜빡거림 제거
//void removeCursor(void)
//{
//	CONSOLE_CURSOR_INFO curInfo;
//	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
//	curInfo.bVisible = 0;
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
//}
//
////커서의 좌표를 (2,1)로 초기화
//void setCursor(int x, int y)
//{
//	COORD pos = { x,y };  //cjl: 좌표 표시하는 구조체
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//cjl:표준콘솔의 핸들값(ID)와 좌표 받아서 커서위치를 바꿈
//}
//
////cjl:콘솔 화면 버퍼에 있는 커서의 좌표
//COORD getCursor(void)
//{
//	COORD cur;
//	CONSOLE_SCREEN_BUFFER_INFO curInfo; //cjl:콘솔 화면 버퍼에 대한 정보
//	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
//	cur.X = curInfo.dwCursorPosition.X;//cjl:콘솔 화면 버퍼에 있는 커서의 좌표
//	cur.Y = curInfo.dwCursorPosition.Y;
//	return cur;
//	/*화면 버퍼: 컴퓨터의 표시 화면. 
//	나타나야 할 내용을 저장하는 기억 장소로 
//	컴퓨터는 주기적으로 이 버퍼의 내용을 화면 접속기에 보내고 
//	화면 접속기는 이를 받아서 지정된 장소에 그려줌으로써 화면이 계속 보이게 된다*/
//}
//
////콘솔화면에 테트리스 게임판 생성
//void showBoard(void)
//{
//	int x, y;
//	//중앙 보드 라인
//	for (x = 1; x <= BOARD_WIDTH + 1; x++)
//	{
//		board[BOARD_HEIGHT][x] = 1; //board 배열 중앙 1인식
//		setCursor((BOARD_X)+x * 2, BOARD_Y + BOARD_HEIGHT);  //콘솔좌표
//		printf("━");
//	}/*x를 1부터 보드의 크기만큼 for문을 돌려주고 board배열에  1로 바꿔주고
//setCursor를 통해서 x에다가 2를 곱해주는데 이유는 곱하지 않으면 반만 출력 되므로 2를 곱해줬다.
//그리고 좌표에다가 경계선을 그려준다*/
//
//
//	//왼쪽 보드 라인
//	for (y = 0; y < BOARD_HEIGHT + 1; y++)
//	{
//		board[y][0] = 1; //board 배열 왼쪽 1인식
//		setCursor(BOARD_X, BOARD_Y + y);
//		if (y == BOARD_HEIGHT)
//			printf("┗");
//		else
//			printf("┃");
//	}/*y를 0부터 높이만큼 for문을 돌려주고 board배열에서 왼쪽 라인을 1로 바꿔주고 y가 보드의 높이랑 같으면
// ’┗’을 출력하고 아니면 ‘┃’을 출력한다.*/
//	//오른쪽 보드 라인
//	for (y = 0; y < BOARD_HEIGHT + 1; y++)
//	{
//		board[y][BOARD_WIDTH + 1] = 1; //board 배열 오른쪽 1인식
//		setCursor(BOARD_X + (BOARD_WIDTH + 2) * 2, BOARD_Y + y);
//		if (y == BOARD_HEIGHT)
//			printf("┛");
//		else
//			printf("┃");
//	}
//
//	//모서리값 값 변경
//	board[20][0] = 1;
//	board[20][11] = 1;
//	//보드판 숫자 보기
//	//setCursor(6,2);
//	//for(y=0; y<=BOARD_HEIGHT; y++){
//	// for(x=0; x<=BOARD_WIDTH+1; x++){
//	//  setCursor(4+(x*2),2+y);
//	//  printf("%d ",board[y][x]);
//	// }
//	// printf("\n");
//	//}
//	puts(" ");
//}
//
////setCursor()와 동일 기능 / 블록 생성 위치를 (13,2)로 설정
//void initial(int x, int y)
//{
//	curX = x;//안 쓰는 전역변수
//	curY = y;//안 쓰는 전역변수
//	setCursor(x, y);//x와 y 파라미터 받아서 setCursor()에 대입
//}
//
////블록끼리 닿는가? 겹치지 않으면 0 겹치면 1 반환
//int detect(int rotation, int move1, int move2)
//{// rotation 변수는 블록 모양을 의미 move1, move2는 이동예정 x,y좌표
//	int x, y;//비교용 임시 좌표 변수
//	int arrX, arrY; //배열좌표저장용
//	COORD pos = getCursor();//현재 좌표로 구조체 초기화
//	arrX = pos.X + move1;//이동예정 x좌표 저장
//	arrY = pos.Y + move2;//이동예정 y좌표 저장
//	arrX = (arrX / 2) - 2;//콘솔좌표->배열 열 변환값 //x축은 y축에 비해 한 칸이 2배 작으므로 콘솔에 출력할때 *2했었음. -2는 콘솔에 출력할때 2칸 띄우고 출력했으므로 사실arrX=(arrX-BOARD_X)/2인듯.
//	arrY = arrY - BOARD_Y;//콘솔좌표->배열 행 변환값// board배열인덱스와 console 좌표를 매칭하기 위해! 
//	for (y = 0; y < 4; y++) 
//	{//4x4번 총 16번 반복(블록크기인 4x4 네모 스캔)
//		for (x = 0; x < 4; x++)
//		{//현재 위치에서 rotation모양 블록이 x나 y축으로 move할 예정인 경우 현재 위치에서 move예정인 좌표에 4x4 테두리 안에 rotation모양 블록을 가상으로 그렸다고 생각했을 때 
//			if ((block[rotation][y][x] == 1) && board[arrY + y][arrX + x] == 1)//그 4x4테두리 안에 있는 보드판 블록이 4x4 rotation모양 블록과 한개라도 겹치면 겹쳤다고 판별   
//				return 1;  //보드와 벽돌 겹침 / 보드에 쌓여있는 블록이나 보드판 테두리 블록과 벽돌 겹친다고 판별
//		}
//	}
//	return 0;  //겹치지 않음
//}
//
////벽돌생성, 배열에 저장된 1을 ■으로 변경
//void showBlock(int rotation)
//{
//	int x, y;
//	COORD cursor = getCursor();
//	int prove;
//	prove = detect(rotation, 0, 0);
//	if (prove == 0){
//		//콘솔창위치 설정, 배열값에서 1은 ■출력,0은 출력없음
//		for (y = 0; y < 4; y++)
//		{
//			for (x = 0; x < 4; x++)
//			{
//				setCursor(cursor.X + (x * 2), cursor.Y + y);//cjl:x는 좁아서 2칸
//				if (block[rotation][y][x] == 1)
//					printf("■");
//			}
//		}
//		setCursor(cursor.X, cursor.Y);
//	}
//}
//
////블록 이동 시 잔상 지움 & 인자로 전달된 move1,move2만큼 커서 이동
//void removeBlock(int rotation, int move1, int move2)
//{
//	int pr;
//	int x, y;
//	COORD cursor = getCursor();
//	pr = detect(rotation, move1, move2); //rotation모양 4x4 블록이 move1, move2만큼 이동한 커서 좌표에 있다고 가정하고
//		//rotation모양 4x4 블록이 보드판 블록이 겹쳤다고 판별될 경우
//	if (pr == 0)//벽이 아니면
//	{
//		for (y = 0; y < 4; y++)
//		{
//			for (x = 0; x < 4; x++)
//			{
//				setCursor(cursor.X + (x * 2), cursor.Y + y);
//				if (block[rotation][y][x] == 1)
//					printf("  ");//벽돌 지움 공백2칸이어야?
//			}
//		}
//		setCursor(cursor.X + move1, cursor.Y + move2);//커서 이동까지..
//	}
//}
//
///*보드판에 새로 고정된 블록의 위치를 BOARD 배열에 반영*/
//void boardConginition(int n, int move1, int move2) //n은 블록의 모양을 의미하는 변수
//{
//	COORD pos = getCursor();//현재위치에 '정박'시킬 것이므로.
//	int arrX = pos.X + move1; //현재 콘솔 커서의 좌표 저장, move1,2는 실질적으로 사용되지 않음
//	int arrY = pos.Y + move2;  
//	int x, y;
//
//	//콘솔의 좌표를 BOARD 배열의 값으로 대응시키기 위한 조작
//	arrX = arrX / 2 - 2; //(arrX-BOARD_X)/2
//	arrY = arrY - 2;  //arrY-BOARD_Y
//	
//	//BOARD에 블록의 모양을 반영, 블록이 4*4 이차원 배열로 이루어져있어서 4번씩 반복하는 것.
//	for (y = 0; y < 4; y++)
//	{
//		for (x = 0; x < 4; x++)
//		{
//			if (block[n][y][x] == 1) 
//			{
//				board[arrY + y][arrX + x] = 1;
//			}
//		}
//	}
//	return;
//}
//
///*보드판에 있는 블록을 한칸씩 내림 /보드배열의 값 변경 후 콘솔로 출력*/
//void array_down(int column)//column에는 삭제할 line의 y좌표가 전달됨.
//{
//	int y, x;//반복문을 위한 변수 y
//	
//	/*벽돌을 모두 채운 line을 지우기 위해 board배열의 값을 한칸씩 내림*/
//	for (y = column; y >= 0; y--) //완성한 line부터 첫번째 라인까지 반복, *y==1일때까지 해야함.
//	{
//		for (x = 1; x <= 10; x++)
//		{
//			board[y][x] = board[y - 1][x];//윗 line에 저장된 값을 아래 line에 대입
//		}
//	}
//	
//	/*board 배열 0행에 0삽입*/
//	for (x = 1; x <= 10; x++)//board[-1][x]일때의 잘못된 값을 바로 잡기 위한 과정
//		board[0][x] = 0;
//
//	/*변경된 board 배열의 값을 바탕으로 콘솔 출력 */
//	for (y = 1; y <= 19; y++)
//	{
//		for (x = 1; x <= 10; x++)
//		{
//			setCursor((BOARD_X)+x * 2+1, y + BOARD_Y);//board 배열의 값을 콘솔로 대응시키기 위한 조작,
//					//+1을 하는 이유: 블록의 x좌표가 홀수 단위로 설정되어있으므로, 홀수로 맞춰주기 위해.
//			if (board[y][x] == 1)
//				printf("■");
//			else
//				printf("  ");//board배열에서 1이 아닌 부분은 빈칸으로 출력
//		}
//	}
//}
//
////콘솔화면에 점수판 생성
//void scoreLevel(void)
//{
//	setCursor(40, 3);
//	printf("★레벨10 게임 클리어★");
//	setCursor(40, 5);
//	printf("레벨:%d\n", level);
//	setCursor(40, 7);
//	printf("점수:%d\n", score);
//}
//
////레벨, 점수 계산 & 플레이 속도 증가
//void countScore(void)
//{
//	score += 10;
//	if (score % 30 == 0)//점수가 30의 배수일때마다 Level Up
//	{
//		level += 1;
//		speed -= 30;//딜레이 '시간' 줄이기->속도가 빨라짐
//	}
//	scoreLevel();//점수판 출력
//}
//
///* 1~10까지 행의 열 전체가 1로되면 블록사라짐.사라지면 array_down함수 실행 */
//void control(void)
//{
//	int i;
//	int x, y;
//	int z = 0;
//	//19행부터 시작해서 1행까지 반복
//	for (y = 19; y >= 1; y--) //아래에서 위로 한칸씩 검사
//	{
//		//한 행당 4번 반복=>내려온 라인을 검사하기 위해.(한번에 사라질 수 있는 라인 수는 최대 4라인이므로)
//		for (z = 0; z < 4; z++)
//		{
//			i = 0;
//			//board[][x]에 블록을 의미하는 값이 저장되어있다.
//			for (x = 1; x < 11; x++)
//			{
//				//행기준
//				if (board[y][x] == 1)
//				{
//					i++;
//					//행에 블록 10개가 전부 채워져있다면 행의 블록 삭제(line clear)
//					if (i == 10)
//					{
//						for (x = 1; x < 11; x++)
//						{
//							setCursor((x + 2) * 2, y + 2);//board 배열의 index를 콘솔 좌표로 변환
//							printf("  ");//블록이 x좌표 2칸을 차지하므로 공백 2칸으로 대체
//						}
//						//행 기준으로 블록 내리기
//						countScore();//line clear마다 점수 올림
//						array_down(y);//clear된 line을 삭제하므로 윗 라인들을 아래로 내림.
//					}
//				}
//			}
//		}
//	}
//}
//
////생성된 블록이 생성되자마자 다른 블록과 부딫히는가?
//int gameOver(int rotation)
//{
//	if (detect(rotation, 0, 0))
//		return 5; //게임 끝
//	else
//		return 0;
//}
//
////레벨이 10인가?
//int gameWin(void)
//{
//	if (level == 10)
//		return 1; //게임승
//	else
//		return 0;
//}
//
//void moveBlock(void)
//{
//	int n;
//	int kb;
//	int prove;//cjl:주석 부족..무슨 변수인지 모르겠
//	srand(time(NULL)); //cjl:srand() 인자 기반 난수를 초기화
//	int c = 2; //cjl: c가 뭐냐.. 매직넘버 2는 뭐고..
//	/*게임 시작~끝*/
//	while (1)
//	{
//		initial(CBLOCK_X, CBLOCK_Y); //블록 생성 위치 설정
//		n = rand() % 7;//블록 모양을 임의로 결정하기 위해 추출하는 수 
//		n = n * 4; //cjl:n은 0~6 사이의 7개의 난수, 도형이 7개/ *4는 왜해??
//		if (gameWin())//레벨이 10이면 콘솔 종료
//		{
//			setCursor(35, 20);
//			printf("GAME WIN");
//			(void)getchar();
//			exit(1);
//		}
//		if (gameOver(n))//생성된 블록이 생성되자마자 다른 블록과 부딫히는가?
//			break;
//		/*블록 한개 위~밑 이동*/
//		while (1)
//		{
//			int ww = 0;//블록 충돌 발생 여부 알리는 flag(닿으면 1)
//			int k = 0;
//			int tmp;
//
//			/*블록 하나가 아래로 떨어지는 과정*/
//			while (!_kbhit())//kbhit():키보드가 눌렸는지 확인. 안눌리면 0반환
//			{
//				//블록을 콘솔에 출력
//				showBlock(n);//난수로 추출한 n은 블록의 종류를 의미(block[n][4][4])
//				
//				//딜레이 타임, DELAY와 전역변수 speed의 값을 바꾸면 시간 조절 가능
//				Sleep(DELAY + speed);
//
//				//한칸 아래로 이동시 블록이 닿는다면
//				if (detect(n, 0, 1) == 1) //0, 1은 각각 x,y좌표를 얼만큼 이동할 것인가를 의미
//				{
//					ww = 1;//flag
//					boardConginition(n, 0, 0);//블록을 보드판에 '정박'시킴. board 배열에 새로 고정된 블록의 정보 입력
//					control();//한줄이 꽉찬 상태라면 그 줄을 제거 후 위쪽 블록들 한칸씩 전부 내리기
//					break;
//				}
//				removeBlock(n, 0, 1);//위치 갱신: 블록을 지우고 콘솔 좌표를 한칸 아래로((0,1)만큼) 이동
//			}
//			//블록이 자리잡았다면 한 블록의 여정이 끝난다. while문 탈출해서 다시 블록 생성부터
//			if (ww == 1)
//				break;
//
//			kb = _getch();//키보드 입력값 받아와 kb에 저장
//
//			/*방향키*/
//			switch (kb)
//			{
//			case LEFT:
//				removeBlock(n, -2, 0);
//				showBlock(n);
//				break;
//			case RIGHT:
//				removeBlock(n, 2, 0);
//				showBlock(n);
//				break;
//			case UP:
//				// 첫수를구한다.
//				k = n / 4;
//				k *= 4;
//				// 다음수가 끝수이하인가?
//				if ((n + 1) <= (k + 3))
//				{
//					k = n + 1;
//				}
//				prove = detect(k, 0, 0);
//				if (prove == 0)
//				{
//					removeBlock(n, 0, 0);
//					n = k;
//					showBlock(n);
//					break;
//				}
//				break;
//			case DOWN:
//				removeBlock(n, 0, 2);
//				//showBlock(n);
//				break;
//			case SPACE:
//				while (1)
//				{
//					removeBlock(n, 0, 1);
//					if (detect(n, 0, 1) == 1)
//					{
//						showBlock(n);
//						boardConginition(n, 0, 0);
//						break;
//					}
//				}
//			}
//		}
//	}
//	setCursor(35, 20);
//	printf("GAME OVER");
//}
//int main()
//{
//	removeCursor(); //커서 깜박이 제거
//	setCursor(2, 1); //보드표시 시작위치 설정
//	showBoard(); //보드 출력
//	scoreLevel();
//	moveBlock(); //보드 출력 움직임
//	(void)getchar();
//}