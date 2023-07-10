SELECT
score,
DENSE_RANK() OVER(ORDER BY score DESC) AS 'rank'
FROM Scores;

--------------------------------------------------

探討:

本題主要是瞭解DENSE_RANK()這個函式的用法，
另一個重點是rank在Mysql 8.0版本是保留字，所以要帶''