package prototype.arctos.cash_e.controller

import android.arch.lifecycle.LiveData
import android.support.annotation.WorkerThread
import prototype.arctos.cash_e.model.Expense

class ExpenseRepository(private val expenseDao: ExpenseDAO) {

    val allExpenses: LiveData<List<Expense>> = expenseDao.getAllExpenses()

    @WorkerThread
    suspend fun insert(expense: Expense) {
        expenseDao.insert(expense)
    }
}