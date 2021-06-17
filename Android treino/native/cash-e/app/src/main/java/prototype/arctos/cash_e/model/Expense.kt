package prototype.arctos.cash_e.model

import android.animation.TypeConverter
import android.arch.persistence.room.ColumnInfo
import android.arch.persistence.room.Entity
import android.arch.persistence.room.PrimaryKey
import android.arch.persistence.room.TypeConverters
import java.sql.Date

@Entity(tableName = "expense")
data class Expense (
    @PrimaryKey(autoGenerate = true) val uid: Long? = null,
    @ColumnInfo(name = "time") val time: Date?,
    @ColumnInfo(name = "cost") val cost: Double?
)