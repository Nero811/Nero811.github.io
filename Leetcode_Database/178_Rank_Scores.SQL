SELECT
score,
DENSE_RANK() OVER(ORDER BY score DESC) AS 'rank'
FROM Scores;

--------------------------------------------------

���Q:

���D�D�n�O�A��DENSE_RANK()�o�Ө禡���Ϊk�A
�t�@�ӭ��I�Orank�bMysql 8.0�����O�O�d�r�A�ҥH�n�a''