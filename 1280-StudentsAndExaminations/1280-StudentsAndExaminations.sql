-- Last updated: 10/4/2026, 10:52:02 PM
# Write your MySQL query statement below
select st.student_id, st.student_name, sb.subject_name, count(e.student_id) as attended_exams 
from (students st, subjects sb) left join examinations e on e.student_id=st.student_id and e.subject_name = sb.subject_name
group by st.student_id,sb.subject_name,st.student_name
ORDER BY
    st.student_id,
    sb.subject_name;