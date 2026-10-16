#ifndef KYTY_LIBS_MICROPHONE_H_
#define KYTY_LIBS_MICROPHONE_H_

#include <atomic>

namespace Libs::Audio {

class Microphone {
public:
	static void SetAvailable(bool available) {
		m_available.store(available, std::memory_order_relaxed);
	}
	[[nodiscard]] static bool IsAvailable() { return m_available.load(std::memory_order_relaxed); }
	static void SetBlowing(bool blowing) { m_blowing.store(blowing, std::memory_order_relaxed); }
	[[nodiscard]] static bool IsBlowing() {
		return IsAvailable() && m_blowing.load(std::memory_order_relaxed);
	}

private:
	static inline std::atomic<bool> m_blowing {false};
	static inline std::atomic<bool> m_available {true};
};

} // namespace Libs::Audio

#endif
