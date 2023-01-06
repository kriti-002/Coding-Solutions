# Write your MySQL query statement below
select s1.id, coalesce(s2.student, s1.student) as student from Seat s1 left join Seat s2 on (s1.id+1)^1=s2.id+1 order by s1.id;