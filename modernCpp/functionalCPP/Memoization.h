
#include <functional>

template<class T, class S>
class Memoization {
    private:
		std::function<T()>	 m_func;
	    T const & (*m_subroutine) ( Memoization *);
		mutable T   m_recordedFunc;
		S&          m_stream;

	    static T const & ForceSubRoutine(Memoization *d){
		    d->m_stream << "\t\t" <<  __FUNCTION__ << "\n";
			d->m_stream .flush();
		    return d->DoRecording();
		}
		static T const& FetchSubroutine ( Memoization *d){
		    d->m_stream << "\t\t" <<  __FUNCTION__ << "\n";
			d->m_stream .flush();
		    return d->FetchRecording();
		}

		T const& FetchRecording(){
		    m_stream << "\t\t" <<  __FUNCTION__ << "\n";
			m_stream .flush();
		    return m_recordedFunc;
		}
		T const& DoRecording() {
		    m_stream << "\t\t" <<  __FUNCTION__ << "\n";
			m_stream .flush();
		    m_recordedFunc = m_func();
			m_subroutine = &FetchSubroutine;
			return FetchRecording();
		}
	public:
	Memoization ( std::function<T()> func, S& stream) : m_func (func),
	m_subroutine (&ForceSubRoutine), m_recordedFunc(T()),m_stream(stream)
	{}
	
	T Fetch(){
	    return m_subroutine(this);
	}
};
