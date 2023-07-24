--------------------------------------------
自己寫的

SELECT requester_id AS id,SUM(count1) AS num FROM(
WITH
Query1 AS (
    SELECT
    requester_id,COUNT(requester_id) AS count1
    FROM RequestAccepted
    GROUP BY requester_id
)
,
Query2 AS (
    SELECT
    accepter_id,COUNT(accepter_id) AS count2
    FROM RequestAccepted
    GROUP BY accepter_id
)

SELECT Query1.requester_id,count1 FROM Query1
UNION ALL
SELECT Query2.accepter_id,count2 FROM Query2
) AS TEMP
GROUP BY requester_id;
ORDER BY num DESC LIMIT 1;

--------------------------------------------
網路解答:

SELECT c.people as id, SUM(c.cnt) AS num
FROM (
SELECT requester_id AS people, COUNT(DISTINCT accepter_id) AS cnt
FROM request_accepted
GROUP BY requester_id

UNION ALL   

SELECT accepter_id AS people, COUNT(DISTINCT requester_id) AS cnt
FROM request_accepted
GROUP BY accepter_id 
) AS c

GROUP BY c.people
ORDER BY SUM(c.cnt) DESC
LIMIT 1;

--------------------------------------------

探討:
本題自己寫了3次才過，
第一次錯是在是用INNER JOIN:
INNER JOIN Query2 ON Query1.requester_id = Query2.accepter_id
ORDER BY num DESC LIMIT 1
這個情況會少判斷到requester_id和accepter_id沒有相對應的值導致答案是NULL，

第二次錯是在用UNION不是用UNION ALL，
只用UNION會少判斷到重複的值，導致最終加總沒加到導致錯誤。