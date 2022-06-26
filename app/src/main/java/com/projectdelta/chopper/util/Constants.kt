package com.projectdelta.chopper.util

import androidx.annotation.Keep

@Keep
@Suppress("KotlinJniMissingFunction") // AS Sync issue :/
class Constants {

	val coreJniVersion : Float
		get() = nativeGetJniVersion()

	@Keep
	private external fun nativeGetJniVersion() : Float

}
