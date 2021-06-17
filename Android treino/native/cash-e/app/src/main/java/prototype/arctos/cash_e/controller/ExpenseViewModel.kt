package prototype.arctos.cash_e.controller

import android.app.Application
import android.arch.lifecycle.AndroidViewModel
import android.arch.lifecycle.LiveData
import kotlinx.coroutines.CoroutineScope
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.Job
import kotlinx.coroutines.launch
import kotlin.coroutines.CoroutineContext
import prototype.arctos.cash_e.model.Expense
import prototype.arctos.cash_e.model.ExpenseRoomDatabase


class ExpenseViewModel(application: Application) : AndroidViewModel(application) {

    private var parentJob = Job()
    private val coroutineContext: CoroutineContext
        get() = parentJob + Dispatchers.Main
    private val scope = CoroutineScope(coroutineContext)

    private val repository: ExpenseRepository
    val allExpenses: LiveData<List<Expense>>

    init {
        val expenseDAO = ExpenseRoomDatabase.getDatabase(application, scope).expenseDao()
        repository = ExpenseRepository(expenseDAO)
        allExpenses = repository.allExpenses
    }

    fun insert(expense: Expense) = scope.launch(Dispatchers.IO) {
        repository.insert(expense)
    }

    override fun onCleared() {
        super.onCleared()
        parentJob.cancel()
    }
}