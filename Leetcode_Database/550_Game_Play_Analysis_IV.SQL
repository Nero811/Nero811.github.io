----------------------------------
自己寫的:

SELECT
ROUND(
    (
        SELECT
        COUNT(1)
        FROM(
            SELECT
            a.player_id
            FROM Activity AS a
            INNER JOIN
            (SELECT player_id,MIN(event_date) AS event_date FROM Activity GROUP BY player_id) AS c
            ON a.event_date = c.event_date AND a.player_id = c.player_id
            INNER JOIN
            Activity AS b
            ON a.player_id = b.player_id AND TIMESTAMPDIFF(DAY,a.event_date,b.event_date) = 1
        ) AS TEMP
    )
    /
    (
        SELECT
        COUNT(DISTINCT player_id)
        FROM Activity
    )
    ,
    2
) AS fraction;

----------------------------------

網路解答:
1.
SELECT ROUND(COUNT(DISTINCT b.player_id)/COUNT(DISTINCT a.player_id), 2) AS fraction FROM Activity AS a
LEFT JOIN
(SELECT player_id, MIN(event_date) AS first_login FROM Activity
GROUP BY player_id) AS b
ON a.player_id = b.player_id
AND DATEDIFF(a.event_date, b.first_login) = 1

2.
SELECT ROUND(COUNT(DISTINCT b.player_id)/COUNT(DISTINCT a.player_id), 2) AS fraction FROM Activity AS a
LEFT JOIN
(SELECT player_id, FIRST_VALUE(event_date) OVER(PARTITION BY player_id ORDER BY event_date) AS first_login FROM Activity) AS b
ON a.player_id = b.player_id
AND DATEDIFF(a.event_date, b.first_login) = 1

----------------------------------

探討:
試了3次才ACCESS，第一次錯是在ROUND()的第一個參數沒有加入COUNT(1) 導致返回多個rows導致錯誤，
第二次錯是在不是寫COUNT(DISTINCT player_id)，而是寫成MAX(player_id)，但測資的player_id有可能是跳著的，
導致統計錯誤的player筆數