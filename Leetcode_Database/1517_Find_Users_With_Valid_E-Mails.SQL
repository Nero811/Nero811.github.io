------------------------------
�ۤv�g�� 

(�Ĥ@�� ���~)
SELECT
user_id,name,mail
FROM Users
WHERE (SUBSTRING_INDEX(mail,"@",-1) = "leetcode.com") AND (
SUBSTRING_INDEX(mail,"@",1) REGEXP '^[A-Z][A-Z0-9_.-]*$');

(�ĤG�� ���T)
SELECT * FROM Users
WHERE (SUBSTRING_INDEX(mail,"@",-1) = "leetcode.com") AND 
mail REGEXP '^[A-Z][A-Z0-9_.-]*@leetcode.com$';

------------------------------

�����ѵ� (����)

SELECT * FROM Users
WHERE mail REGEXP '^[A-Z][A-Z0-9_.-]*@leetcode.com$';


------------------------------


���Q:
���D�n�ϥΥ��W���F�����D�A
�ۤv�Ĥ@����SUBSTRING_INDEX����r��A���O���ո�Ʀ��i��|�����@�A�ɭPSUBSTRING_INDEX(mail,"@",1)�|SELECT�h����� �p: Naftali@JQQPcQcHLG@leetcode.com�A
��ӰѦҺ����Ѫk�A�]�O�����A�]���u���P�_com�����A��Ƥ]���i��O@leetcode?com�����C

���D�٦��ӭ��I�O*���Ϊk�A�ݭn��*�~�|���_�h���r��C

