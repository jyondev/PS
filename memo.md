- 자료구조 (Data Structure)
    - Vector
        크기가 변하는 배열, 인덱스로 바로 접근 가능
    - List
        이중 연결 리스트, 중간 삽입/삭제가 빠름
    - Deque
        양쪽이 뚫린 벡터, 앞/뒤 삽입,삭제 빠름

    - Stack
        LIFO / DFS,되돌리기,괄호 검사
    - Queue
        FIFO / BFS,순서대기열
    - Priority Queue
        우선순위로 정렬한 큐 / 다익스트라, 최댓값 관리

    - Map
        key-value 쌍 / tree
    - Set
        key만 저장 (중복X)

- 각 문제별 풀이법
    - Hash
        - 쓰는 경우
            배열을 쓰기엔 인덱스가 너무 크거나 문자열인 경우
            '중복 확인', '빈도수 세기', '두 배열 비교'
            N이 10만 이상인데 검색을 많이 해야 하는 경우 (O(1))
        - STL
            unordered_map<key,value>: 순서 없이 빠름, 정렬이 필요 없는 경우
            map<key,value>: key 기준으로 정렬
            unordered_set<key>: 중복 제거용 집합
        - 풀이법
            1. map 선언.
            2. 데이터를 넣으며 카운팅. (m[key]++)
            3. 조건에 맞는 key를 찾는다.
    
    - Stack/Queue
        - 쓰는 경우
            - 스택(LIFO)
                '짝 맞추기', '최근에 넣은 것', '뒤로 가기', DFS
            - 큐(FIFO)
                '순서대로 처리', '줄 세우기', BFS
        - STL
            stack<int>, queue<int>
            deque<int>: 앞 뒤로 뺄 수 있는 vector
        - 풀이법
            문제를 시뮬레이션하며 push,pop,top/front 사용
    - Heap
        - 쓰는 경우
            데이터가 계속 추가/삭제되는데 '가장 큰 값' 또는 '가장 작은 값'이 필요할 때
            Dijkstra
        - STL
            priority_queue<int>: max-heap (내림차순)
            priority_queue<int,vector<int>,greater<int>>: min-heap (오름차순)
        - 풀이법
            push로 데이터 다 넣기
            while(!..empty())에서 top() 꺼내고 계산
    - Sorting
        - 쓰는 경우
            데이터를 순서대로 보고 싶을 때
            greedy, binary_search를 쓰기 전 필수
            '가장 큰 수 만들기'
        - STL
            sort(v.begin(), v.end())
            sort(v.begin(), v.end(), cmp): cmp 함수(커스텀 정렬)
    - Brute Force
        - 쓰는 경우
            입력 크기가 작을 때
            모든 경우의 수를 찾을 때
            N <= 20: 재귀(백트래킹) 가능
            N <= 100: 3중 반복문 가능
        - 풀이법
            시간 복잡도 계산 필수
    - Greedy
        - 쓰는 경우
            미래를 고려하지 않고 현재의 최선을 선택해도 전체 최적해가 나오는 경우
        - 필수
            정렬(Sorting)
            힙(Heap)
        - 풀이법
            1. 기준 세우기
            2. 정렬
            3. 앞에서부터 보며 조건 맞으면 선택하기
    - DP
        - 쓰는 경우
            '경우의 수', '최댓값/최솟값' 구하기
            큰 문제를 작은 문제로 쪼갤 수 있을 때(피보나치)
        - 풀이법
            1. dp 배열 선언
            2. 초기값 설정(dp[0], dp[1])
            3. 반복문으로 채우기
    - DFS/BFS
        - 쓰는 경우
            - DFS (깊이 우선)
                '모든 경로 탐색', '사이클 찾기', '미로 찾기'
            - BFS (너비 우선)
                '최단 거리', '확산'
        - STL
            - DFS
                재귀함수, 스택
            - BFS
                큐 + while문
        - 풀이법
            최단 거리 나오면 BFS
            백트래킹, 재귀는 DFS
    - Binary Search
        - 쓰는 경우
            입력 범위가 억 단위로 비정상적으로 클 때
            '최댓값의 최솟값 구하기'
            '특정 값 빠르게 찾기'
        - 필수
            데이터 정렬
            left,right,mid 변수
            STL: 
                lower_bound: 특정 값 이상의 값이 처음 나타나는 위치 반환 
                upper_bound: 특정 값 이하의 값이 처음 나타나는 위치 반환
                binary_search: 정렬된 범위 내에 원소 존재 유무
        - 풀이법
            left= 최소, right=최대
            while(left<=right) mid값 검사
    - Graph
        - 쓰는 경우
            Dijkstra: 가중치가 있는 그래프의 최단 경로
            Floyd-Warshall: 모든 정점에서 모든 정점으로의 최단 경로(N<=500)
            MST: 모든 지점을 연결하는 최소 비용
        - STL
            인접 리스트(vector<vector<pair<...>>>)
            다익스트라(priority_queue)