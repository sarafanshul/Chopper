package com.projectdelta.chopper.ui.main

import android.annotation.SuppressLint
import android.os.Bundle
import com.projectdelta.chopper.databinding.ActivityMainBinding
import com.projectdelta.chopper.ui.base.BaseViewBindingActivity
import com.projectdelta.chopper.util.Constants
import dagger.hilt.android.AndroidEntryPoint
import timber.log.Timber

@AndroidEntryPoint
class MainActivity : BaseViewBindingActivity<ActivityMainBinding>() {


	@SuppressLint("SetTextI18n")
	override fun onCreate(savedInstanceState: Bundle?) {
		super.onCreate(savedInstanceState)

		_binding = ActivityMainBinding.inflate(layoutInflater)
		setContentView(binding.root)

		// Example of a call to a native method
		binding.sampleText.text = Constants.coreJniVersion.toString() + "  " + Constants.openCVVersion

	}

	override fun onNetworkStateChange(isNetworkAvailable: Boolean) {
		super.onNetworkStateChange(isNetworkAvailable)
		Timber.d("Network change : online : $isNetworkAvailable")
	}

}
