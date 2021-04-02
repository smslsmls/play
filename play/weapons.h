//무기 성능
typedef struct {
	string name;
	enum_rarity rarity;
	int weapon_skill_code;
	stat_struct plus_stat;
}weapon_status; 
enum weapons{
	//레이피어
	//에페
	EPEE,
	//플뢰레
	FLEURET,
	//스몰소드
	SMALLSWORD,
	//에스파다 로페라
	ESPADAROPERA,
	//미스틸테인
	MISTILTEINN,
	//검
	//롱소드
	LONGSWORD,
	//발키리소드
	VALKYRIESWORD,
	//글라디우스
	GLADIUS,
	//바스타드소드
	BASTARDSWORD,
	//후츠노미타마
	FUTSUNOMITAMA,
	//쌍룡검
	DOUBLEDRAGONSWORD,
	//엑스칼리버
	EXCALIBUR,
	//다인슬레이프
	DAINSLEIF,
	//클레이모어
	CLAYMORE,
	//프람베르그
	FLAMBERGE,
	//마법검
	//티르빙
	TYRFINGR,
	//단검
	//대거
	DAGGER,
	//메인고쉬
	MAINGAUCHE,
	//클라우솔라스
	CLAIOMHSOLAIS,
	//소드브레이커
	SWORDBREAKER,
	//창
	//궁니르
	GUNGNIR,
	//롱기누스의창
	LONGINUS,
	//루인
	RUIN,
	//트리아이나(포세이돈의 창)
	TRIAINA,
	//트리슈라(인도의 파괴의 신 시바의 창)
	TRIDENT,
	//치도
	//마체테
	MACHETE,
	//시미터
	SCIMITAR,
	//쿠크리
	KUKRI,
	//팔시온, 펄션
	FALCHION,
	//대검
	//드래곤슬레이어
	DRAGONSLAYER,
	//듀랜달, 뒤랑달
	DURANDAL,
	//그람
	GRAM,
	//레바테인
	LAEATEINN,
	//발뭉
	BALMUNG,
	//아론다이트
	ARONDIGHT,
	//에케작스
	ECKESACHS,
	//망치
	//묠니르
	MOLNIR,
	//대장장이의 망치
	BLACKSMITHHAMMER
};
