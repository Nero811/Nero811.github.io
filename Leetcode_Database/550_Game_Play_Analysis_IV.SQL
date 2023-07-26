----------------------------------
�ۤv�g��:

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

�����ѵ�:
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

���Q:
�դF3���~ACCESS�A�Ĥ@�����O�bROUND()���Ĥ@�ӰѼƨS���[�JCOUNT(1) �ɭP��^�h��rows�ɭP���~�A
�ĤG�����O�b���O�gCOUNT(DISTINCT player_id)�A�ӬO�g��MAX(player_id)�A�����ꪺplayer_id���i��O���۪��A
�ɭP�έp���~��player����