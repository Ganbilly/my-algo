import heapq
INF = 1e9 + 7

class Node:
    def __init__(self, l):
        self.i = l[1]      # 다음 방의 번호 index
        self.d = l[0]      # 방까지의 거리 dist
        self.s = l[2]      # 현재 폭탄들의 상태 status

def solution(n, start, end, roads, traps):
    answer = 0
    flag = 0
    pq = []
    # l[a][b] = node, a는 출발지점 b는 정방향이면 0, 역방향이면 1, node는 
    l = [list([[], []]) for _ in range(n + 1)]
    # dist[n][j] = 폭탄들의 상태가 j일때, n 까지 가는 최단거리 
    dist = [list([INF] * (1 << len(traps))) for _ in range(n + 1)]
    # t 는 폭탄의 순서 t{2:0} => 2번방은 0번폭탄이라는 뜻        
    t = {}
    
    for i in range(len(traps)):
        t[traps[i]] = i;    
    
    for i in range(len(roads)):
        p, q, s = roads[i]
        node = Node([s, q, 0])
        l[p][0].append(node)
        if (p in t) or (q in t):
            node = Node([s, p, 0])
            l[q][1].append(node)
    
    node = Node([0, start, 0])
    heapq.heappush(pq, [node.d, node.i, node.s])
    dist[start][0] = 0 
    
    while len(pq) != 0:
        node = Node(heapq.heappop(pq))
        
        if node.i == end:
            answer = node.d
            break;
        
        cpush = 0
        
        # 비트마스킹을 이용해서 현재 노드의 상태와 큐안에 있던 노드상태를 비교
        if (node.i in t) and ((node.s & (1 << t[node.i])) > 0):
            cpush = 1
        
        for i in range(2):
            for j in range(len(l[node.i][i])):
                next = l[node.i][i][j]
                npush = 0
                
                if(next.i in t) and ((node.s & (1 << t[next.i])) > 0):
                    npush = 1
                # 지금 트랩상태와 다음노드 트랩상태를 (a,b)라고하면 (0, 0)이거나 (1, 1)이면  정방향 (0, 1), (1, 0)이면 역방향으로 이동해야함
                flag = cpush ^ npush

                if flag != i:
                    continue
                
                if dist[next.i][node.s] > node.d + next.d:
                    dist[next.i][node.s] = node.d + next.d
                    if next.i in t:
                        tmp = Node([node.d + next.d, next.i, node.s ^ (1 << t[next.i])])
                        heapq.heappush(pq, [tmp.d, tmp.i, tmp.s])
                    else :
                        tmp = Node([node.d + next.d, next.i, node.s])
                        heapq.heappush(pq, [tmp.d, tmp.i, tmp.s])
                        
    return answer

# 테스트 케이스 시험용 코드
n = 4
start = 1;
end = 4
roads = [[1, 2, 1], [3, 2, 1], [2, 4, 1]]
traps = [2, 3]

result = solution(n, start, end, roads, traps)

print(result)