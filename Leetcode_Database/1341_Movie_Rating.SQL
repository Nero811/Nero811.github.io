自己解答:

WITH
Query1 AS(
SELECT
    name
FROM Users INNER JOIN (
    SELECT
        user_id,COUNT(movie_id) AS count
    FROM MovieRating
    GROUP BY user_id
) AS temp1 ON Users.user_id = temp1.user_id
ORDER BY count DESC,name ASC
LIMIT 1)
,
Query2 AS(
SELECT
    title
FROM Movies INNER JOIN (
    SELECT
        movie_id,AVG(rating) AS avg
    FROM MovieRating
    WHERE created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY movie_id
) AS temp2 ON Movies.movie_id = temp2.movie_id
ORDER BY avg DESC,title ASC
LIMIT 1)

SELECT name AS results FROM Query1
UNION ALL
SELECT title As results FROM Query2;


----------------------------------------------------------------------------

網上解答:

(
SELECT name AS results FROM Users AS a
JOIN Movie_Rating AS b
ON a.user_id = b.user_id
GROUP BY b.user_id
ORDER BY COUNT(DISTINCT movie_id) DESC, name ASC
LIMIT 1
)
UNION ALL
(
SELECT title AS results FROM Movies AS a
JOIN Movie_Rating AS b
ON a.movie_id = b.movie_id
WHERE LEFT(b.created_at,7) = '2020-02'
GROUP BY b.movie_id
ORDER BY AVG(b.rating) DESC, title ASC
LIMIT 1
);

----------------------------------------------------------------------------

問題探討:
第一次寫時，只有寫UNION導致沒有返回重複的筆數，
後來在UNION後加入ALL就ACCESS這題了。